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
    cin>>x; //14
    vector<int>ans;

    int now = 1;
    while(now <= x)
    {
        ans.push_back(now);
        now*=2;
    }
    // ans = 1, 2, 4, 8

    if(ans.back()!=x)
    {
        int diff = x - ans.back(); //14 - 8 = 6 = 4 + 2
        for(int i=30;i>=0;i--)
        {
            if(diff&(1<<i)) // diff = 6 =        110
                            // (1<<2) = 2^2 = 4= 100
                            //                   100
            {
                ans.push_back(ans.back() + (1<<i)); // 1,2,4,8,12,14
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
