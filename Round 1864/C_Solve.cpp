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
const int N = 4e5 + 5;
typedef pair<int,int> pii;

void TEST_CASES()
{
    int x;
    cin>>x;
    vector<int>ans;

    int now = 1;
    while(now <= x)
    {
        ans.push_back(now);
        now*=2;
    }

    if(ans.back()!=now)
    {
        int diff = x - ans.back();
        for(int i=30;i>=0;i--)
        {
            if(diff&(1<<i))
            {
                ans.push_back(ans.back() + (1<<i));
            }
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<"\n";
    for(int i:ans)
        cout<<i<<" ";
    cout<<"\n";
}

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
