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
const int N = 1e5 + 5;
typedef pair<int,int> pii;

vector<int>all[N];
int n,k;

void TEST_CASES()
{
    cin>>n>>k;
    // Clear
    for(int i=0;i<=k;i++)
    {
        all[i].clear();
    }
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        // which positions the color a[i] occurred
        all[a[i]].push_back(i);
    }
    set<int>st;
    for(int i=0;i<n;i++)
        st.insert(i);
    for(int i=1;i<=k;i++)
    {
        if(all[i].empty())
        {
            cout<<"0 ";
            continue;
        }

        int xmin = *st.begin();
        int xmax = *st.rbegin();
        int ymin = xmin;
        int ymax = xmax;
        int ans = (xmax - xmin + 1) + (ymax - ymin + 1);
        cout<<ans<<" ";
        for(int j:all[i])
            st.erase(j);
    }
    cout<<"\n";
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
