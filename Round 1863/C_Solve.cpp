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
const int N = 4e5 + 5;
typedef pair<int,int> pii;

void TEST_CASES()
{
    int n,k;
    cin>>n>>k;
    k%=(n+1);
    vector<int>a(n);
    vector<bool>vis(n+1);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        vis[a[i]] = 1;
    }

    int nai = -1;
    for(int i=0; i<=n; i++)
        if(vis[i]==0)
            nai = i;

    deque<int>dq(a.begin(),a.end());
    vector<int>all;

    for(int i=0; i<=n; i++)
    {
        all.push_back(dq.front());
        int val = nai;
        nai = dq.back();
        dq.pop_back();
        dq.push_front(val);
    }

    int idx = k;
    for(int i=0; i<n; i++)
    {
        cout<<all[idx]<<" ";
        idx--;
        if(idx<0)
            idx = all.size()-1;
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
