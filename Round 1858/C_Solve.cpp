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
    // ans = floor(n/2)

    vector<int> vis(n+1);
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        int now = i;
        while(now <= n)
        {
            if(vis[now])
            {
                break;
            }
            vis[now] = 1;
            ans.push_back(now);
            now*= 2;
        }
    }
    for(int i:ans)
        cout<<i<<" ";
    cout<<"\n";
}




/*
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
