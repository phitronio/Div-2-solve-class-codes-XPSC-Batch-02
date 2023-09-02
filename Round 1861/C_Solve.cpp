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
    string s;
    cin>>s;
    int n = s.size();
    // 0 -> not sorted
    // 1 -> sorted
    // 2 -> maybe sorted
    vector<int>all;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')
        {
            if(all.empty())
                continue;
            if(all.back()==0)
            {
                cout<<"NO\n";
                return;
            }
            for(int j=(int)all.size()-1;j>=0;j--)
            {
                if(all[j]==2)
                    all[j] = 1;
                else break;
            }
        }
        else if(s[i]=='0')
        {
            if(all.empty() || all.back()==1)
            {
                cout<<"NO\n";
                return;
            }
            all.back() = 0;
        }
        else if(s[i]=='+')
        {
            if(all.empty())
            {
                all.push_back(1);
            }
            else
            {
                if(all.back()==1)
                    all.push_back(2);
                else if(all.back()==2)
                    all.push_back(2);
                else
                    all.push_back(0);
            }
        }
        else
        {
            all.pop_back();
        }
    }
    cout<<"YES\n";
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
