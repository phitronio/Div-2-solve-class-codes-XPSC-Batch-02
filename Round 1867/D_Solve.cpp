#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef LOAKL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 1e5 + 5;
typedef pair<int,int> pii;

int n,k;
vector<vector<int>>g,gr;
vector<bool> used;
vector<int> order, component;

void dfs1 (int v)
{
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v)
{
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}


void TEST_CASES()
{
    cin>>n>>k;

    g.clear();
    gr.clear();
    order.clear();
    component.clear();

    g.resize(n);
    gr.resize(n);

    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]--;
        g[i].push_back(a[i]); // i-> a[i]
        gr[a[i]].push_back(i); // a[i] -> i
    }

    if(k==1)
    {
        for(int i=0; i<n; i++)
        {
            if(a[i]!=i)
            {
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    }

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);

    used.assign (n, false);
    vector<int>len; // vector all cycle lengths
    for (int i=0; i<n; ++i)
    {
        int v = order[n-1-i];
        if (!used[v])
        {
            dfs2 (v);
            if(component.size()==1)
            {
                int x = component[0];
                if(g[x][0]==x)
                    len.push_back(component.size()); //self loop or 1 length cycle
            }
            else
            {
                len.push_back(component.size());
            }
            component.clear();
        }
    }

    for(int i:len)
    {
        if(i!=k)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}


int32_t main()
{
#ifndef LOAKL
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
