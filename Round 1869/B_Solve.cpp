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
typedef pair<ll,ll> pii;

int n,k,a,b;
pii points[N];

ll getDist(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll getMinDist(pii a)
{
    ll ans = 1e18;
    for(int i=0;i<k;i++)
    {
        ans = min(ans, getDist(a, points[i]));
    }
    return ans;
}

void TEST_CASES()
{
    cin>>n>>k>>a>>b;
    a--;
    b--;
    for(int i=0;i<n;i++)
    {
        cin>>points[i].first>>points[i].second;
    }

    ll ans = getDist(points[a] , points[b]);

    if(k)
    {
        ans = min(ans , getMinDist(points[a]) + getMinDist(points[b]));
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
