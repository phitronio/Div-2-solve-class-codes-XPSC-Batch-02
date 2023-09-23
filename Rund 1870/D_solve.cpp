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
typedef pair<ll,ll> pii;


void TEST_CASES()
{
    ll n,k;
    cin>>n;
    // (index , cost)
    vector<pii>a(n);
    for(int i=0; i<n; i++)
    {
        a[i].first = i;
        cin>>a[i].second;
    }
    cin>>k;

    // make the array increasing a1 < a2 < a3 ...
    vector<pii>b;
    for(int i=0; i<n; i++)
    {
        // a = [5,6,3]
        // b = [5]
        // b = [5,6]
        // b = [3]
        while(b.size() && b.back().second >= a[i].second)
        {
            b.pop_back();
        }
        b.push_back(a[i]);
    }
    a = b;


    vector<ll>ans(n);
    ll last_index = -1;
    for(int i=0; i<a.size(); i++)
    {
        ll index = a[i].first;
        // extra cost to pay
        ll pay = a[i].second - (i-1>=0? a[i-1].second : 0);

        // how much to add from last_index + 1 to index
        ll add = k/pay;
        if(i-1>=0)
            add = min(add, ans[last_index]);

        //update current coin
        k -= add * pay;

        for(int j=last_index+1; j<=index; j++)
        {
            ans[j] += add;
        }
        last_index = index;
    }
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
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
