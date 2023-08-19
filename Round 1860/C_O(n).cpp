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
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int> canWin (n);
    int minTillNow = INT_MAX;
    int minLose = INT_MAX;
    for(int i=0; i<n; i++) //O(n)
    {
        if(minTillNow > a[i])
        {
            minTillNow = a[i];
            canWin[i] = 1;
            continue;
        }
        if(minLose < a[i])
        {
            canWin[i] = 1;
        }
        else
        {
            canWin[i] = 0;
            minLose = min(minLose , a[i]);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(canWin[i]==0)
            ans++;
    }
    cout<<ans<<"\n";
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
