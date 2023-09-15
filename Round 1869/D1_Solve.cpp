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

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum%n)
    {
        cout<<"No\n";
        return;
    }
    ll avg = sum/n;

    vector<int>cnt(35,0);

    for(int i=0; i<n; i++)
    {
        ll baki = a[i] - avg;
        if(baki==0)
            continue;

        int add = -1;
        int rem = -1;
        for(int y=0; y<=30; y++)
        {
            ll k = baki + (1ll << y);
            int on = __builtin_ctzll(k);
            if(k>0 && __builtin_popcountll(k)==1)
            {
                add = y;
                rem = on;
            }
        }
        if(add==-1)
        {
            cout<<"No\n";
            return;
        }
        cnt[add]++;
        cnt[rem]--;
    }
    for(int i=0; i<cnt.size(); i++)
    {
        if(cnt[i])
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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
