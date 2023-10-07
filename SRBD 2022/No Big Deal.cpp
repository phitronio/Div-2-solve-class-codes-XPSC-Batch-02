#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 2e5 +5;
typedef pair<int,int> pii;



int n;
ll a[N];
ll p[N];

ll getXor(ll l, ll r)
{
    if(l-1>=0)
        return p[r]^p[l-1];
    else
        return p[r];
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        p[i] = a[i]^p[i-1];
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll x = n+1;
        ll start = l%x;
        ll finish = r%x;
        if((r-l+1)%x==0)
        {
            cout<<"0\n";
            continue;
        }
        if(start<=finish)
        {
            cout<<getXor(start,finish)<<"\n";
        }
        else
        {
            cout<<(getXor(start,n) ^ getXor(0ll, finish))<<"\n";
        }
    }
    return 0;
}
