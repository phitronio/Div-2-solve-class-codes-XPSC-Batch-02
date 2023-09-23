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
typedef pair<int,int> pii;

void TEST_CASES()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);

    // Option 1: a1 xor a2 xor ... an
    int xr1 = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        xr1 ^= a[i];
    }
    // Option 2: (a1 | orr) xor (a2 | orr) xor ... (an | orr)
    int orr = 0;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        orr |= b[i];
    }
    int xr2 = 0;
    for(int i=0;i<n;i++)
    {
        xr2 ^= (a[i]|orr);
    }
    cout<<min(xr1,xr2)<<" "<<max(xr1,xr2)<<"\n";
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
