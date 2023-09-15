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

int mex(set<int>&st) // {0,1,2,4,5} // 0 -> exist
                                    // 1 -> exist
                                    // 2 -> exist
                                    // 3 -> x
                    // {0,1,2,3,4,5,6} -> 7
                    // nlogn
{
    for(int i=0;;i++) //o(n)
    {
        if(st.find(i)==st.end()) //O(logn)
            return i;
    }
}

int n,m;

int gridMex(vector<vector<int> >&a)
{
    set<int>all;
    for(int i=0;i<m;i++)
    {
        set<int>cur;
        for(int j=0;j<n;j++)
        {
            cur.insert(a[j][i]);
        }
        all.insert(mex(cur));
    }
    return mex(all);
}

void rightShift(vector<int>&a, int x)
{
    deque<int>b(a.begin(),a.end());
    for(int i=0;i<x;i++)
    {
        b.push_front(b.back());
        b.pop_back();
    }
    a = vector<int>(b.begin(),b.end());
}

void TEST_CASES()
{
    cin>>n>>m;
    vector<vector<int> >a(n,vector<int>(m));
    vector<int>perm;
    for(int i=0;i<m;i++)
        perm.push_back(i); // 0 , 1, 2,3,4,5 .. m-1
    for(int i=0;i<n;i++)
    {
        a[i] = perm;   // 0,1,2,3..m-1
                        // 0,1,2,3..m-1
    }
    if(m>1)
    {
        int x = 1;
        for(int i=0;i<n;i++)
        {
            rightShift(a[i] , x);
            if(x==m-1)
                continue;
            x++;
        }
    }
    cout<<gridMex(a)<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
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
