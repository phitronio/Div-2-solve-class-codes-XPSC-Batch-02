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
    ll n,m,d;
    cin>>n>>m>>d;
    vector<ll>a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    ll sum = m;
    for(int i=0;i<m-1;i++)
    {
        ll cur = a[i];
        ll nxt = a[i+1];
        sum += (nxt - cur - 1) / d;
    }
    if(a[0] != 1)
    {
        sum += (a[0] - 2) / d;
        sum += 1;
    }
    sum += (n-a[m-1])/d;

    vector<ll> con(m);
    ll ans = 1e18;
    for(int i=1;i<m-1;i++)
    {
        ll prv = a[i-1];
        ll nxt = a[i+1];
        ll now = a[i];
        ll tmp = sum;
        tmp -= (now - prv -1) /d;
        tmp -= (nxt - now -1) /d;
        tmp--;

        tmp += (nxt-prv-1)/d;
        con[i] = tmp;
        ans = min(ans , tmp);
    }

    // remove 0th seller
    {
        ll tmp = sum;
        if(a[0] != 1)
        {
            tmp -= (a[0] - 2) / d;
            tmp -= 1;
        }
        tmp--;
        tmp -= (a[1]-a[0]-1)/d;
        tmp += (a[1] - 2)/ d;
        tmp++;
        ans = min(ans , tmp);
        con[0] = tmp;
    }
    // remove m-th seller
    {
        ll tmp = sum;
        tmp -= (n-a[m-1])/d;
        tmp--;
        tmp -= (a[m-1]-a[m-2]-1)/d;
        tmp += (n-a[m-2])/d;
        ans = min(ans , tmp);
        con[m-1] = tmp;
    }
    cout<<ans<<" ";
    ll cnt = 0;
    for(int i=0;i<m;i++)
    {
        cnt += (con[i] == ans);
    }
    cout<<cnt<<"\n";
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
