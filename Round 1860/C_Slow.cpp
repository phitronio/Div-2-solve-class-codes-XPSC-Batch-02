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
    // O(n^2)
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> canWin (n); // for bob
    for(int i=0;i<n;i++) //O(n)
    {
        int win = 0;
        int lose = 0;
        for(int j=0;j<i;j++) //O(n)
        {
            if(a[j] < a[i])
            {
                if(canWin[j]==0)
                    lose++;
                else win++;
            }
        }
        if(win==0 && lose==0)
        {
            canWin[i] = 1;
        }
        else if(lose)
        {
            canWin[i] = 1;
        }
        else{
            // sob winning state
            canWin[i] = 0;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(canWin[i]==0)
            ans++;
    }
    cout<<ans<<"\n";
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
