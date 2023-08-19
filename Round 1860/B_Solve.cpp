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
    ll m,k,a1,ak;
    cin>>m>>k>>a1>>ak;
    // case 1
    if(ak*k >= m)
    {
        m %= k;
        // m ke a1 ta 1 value r coin diye banabo
        // m - a1 <=0 -> 0
        // m - a1
        ll ans = max(0ll , m - a1);
        cout<<ans<<"\n";
        return;
    }
    m -= ak*k;
    if(a1 >= m)
    {
        cout<<"0\n";
        return;
    }
    // m - a1
    ll ans = (m-a1)/k + (m-a1)%k;
    if(a1 >= m%k){
        ans = min(ans , (m-a1+k-1)/k);
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
