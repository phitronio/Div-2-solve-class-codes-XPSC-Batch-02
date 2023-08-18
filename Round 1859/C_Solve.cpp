#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 2e5 +5;
typedef pair<int,int> pii;



void TEST_CASES()
{
    int n;
    cin>>n;
    // max fix
    int ans = -1;
    // cost = sum(i*pi)- max(i*pi)
    for(int i=1; i<=n; i++) // O(n)
    {
        for(int pi=1; pi<=n; pi++) // O(n)
        {
            int maxi = i*pi;
            vector<int>all;
            int cur = 0;
            int cost = 0;
            for(int index=n; index>=1; index--) // O(n)
            {
                int limit = maxi / index;
                while(cur < limit && cur <n)
                {
                    cur++;
                    if(cur != pi)
                    {
                        all.push_back(cur);
                    }
                }
                if(index==i)
                    continue;
                if(all.empty())
                {
                    cost= -1;
                    break;
                }
                cost += (index * all.back());
                all.pop_back();
            }
            ans = max(ans, cost);
        }
    }
    cout<<ans<<"\n";
}
/*
O(n^3)
*/

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
