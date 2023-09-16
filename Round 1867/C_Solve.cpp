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

int query(int x)
{
    cout<<x<<endl;
    int y;
    cin>>y;
    assert(y!=-2);
    return y;
}

void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]] = 1;
    }
    int mex = -1;
    for(int i=0;;i++)
    {
        if(!mp.count(i))
        {
            mex = i;
            break;
        }
    }

    int last = mex;
    while(1)
    {
        int y = query(last);
        if(y==-1)
        {
            return;
        }
        last = y;
    }
}


int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        TEST_CASES();
    }
    return 0;
}
