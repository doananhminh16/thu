#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#define di first //đi
#define de second  //đến

using namespace std;
typedef  pair<int, int> oco;

struct cap{
    int s, t;
    int d;
    cap(){}
    cap (int i, int j, int dij) : s(i), t(j), d(dij) {
    }
};
typedef list<cap> path;

int step (oco x, oco y)
{
    return (abs(x.first-y.first) + abs(x.second - y.second));
}
bool compd(cap a, cap b)
{
    return a.d<b.d;
}
bool compt(cap a, cap b)
{
    return a.t<b.t;
}
int main()
{
    int n;    cin >>n;
    while (n>0)
    {
        vector <oco> os(n+1), ot(n+1);
        path res;
        vector <path> f(n+1);
        vector <bool> chked(n+1, 0);
        for (int i = 1; i<=n; i++)
        {
            os[i].first = i;
            cin>> os[i].second;
        }
        for (int j = 1; j<=n;j++)
        {
            ot[j].first = j;
            cin>> ot[j].second;
            for (int i = 1; i<=n; i++)
            {
               f[i].emplace_back(i, j, step(os[i], ot[j]));
            }
        }

      /* for (int i =1; i<=n; i++)
       {
           for (auto x: f[i])
           cout <<x.s<<x.t<<x.d<<" ";
           cout<<endl;
       }*/

      while (res.size()<n)
       {
            int ires = 0;
            cap c(0, 0,-1);
           for (int i = 1; i<=n; i++)
           {
               if (!chked[i])
               {
                   f[i].sort(compd);
                   if (f[i].front().d>c.d)
                   {
                       ires = i;
                       c= f[i].front();
                   }
               }
           }
           chked[ires] = 1;
           res.push_back(c);
           cap tcap(0, c.t, 0);
           for (int i = 1; i<=n; i++)
           {
               if (!chked[i])
               {
                   f[i].sort(compt);
                   auto it = lower_bound(f[i].begin(), f[i].end(), tcap, compt);
                   if (it!=f[i].end()) f[i].erase(it);
               }
           }
       }
       int kq=0;
       for (auto x: res)
       //cout <<x.s<<x.t<<x.d<<" ";
           kq=kq+x.d;
           cout<<kq<<endl;
       cin>>n;
    }

    return 0;
}
