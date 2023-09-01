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
    k%=(n+1); // k [0 .. n]
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

    deque<int> dq(a.begin(),a.end());

    for(int i=0; i<k; i++)
    {
        //dq = [1,2,3,4,5]
        // nai = 0

        int val = nai;
        // dq = [0,1,2,3,4,5]
        dq.push_front(val); // O(1)
        // nai = 5
        nai = dq.back();
        // dq = [0,1,2,3,4]
        dq.pop_back();
    }

    for(int i=0;i<dq.size();i++)
        cout<<dq[i]<<" ";
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
