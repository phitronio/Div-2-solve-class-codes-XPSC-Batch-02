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
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==t[i] && s[i+1] == t[i+1] && s[i]=='0' && s[i+1]=='1')
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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
