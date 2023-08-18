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
    vector<int>a;
    for(int i=1;i<=n;i++)
        a.push_back(i);
    int ans = 0;
    do{
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(__gcd(a[i] , a[(i+1)%n]));
        }
        ans = max(ans , (int)st.size());
    }while(next_permutation(a.begin(),a.end()));
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
