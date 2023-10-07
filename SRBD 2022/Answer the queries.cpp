#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 1e5 +5;
const int M = 65;
typedef pair<int,int> pii;

struct FenwickTree
{
    vector<array<int,M> > bit;  // binary indexed tree
    int n;

    void init(int n)
    {
        this->n = n;
        bit.resize(n);
        for(int i=0; i<n; i++)
        {
            fill(bit[i].begin(),bit[i].end(),0);
        }
    }
    array<int,M> sum(int r)
    {
        array<int,M> ret;
        fill(ret.begin(),ret.end(),0);
        for (; r >= 0; r = (r & (r + 1)) - 1)
        {
            for(int j=0; j<M; j++)
                ret[j] += bit[r][j];
        }
        return ret;
    }

    array<int,M> sum(int l, int r)
    {
        array<int,M> x1 = sum(r);
        array<int,M> x2 = sum(l - 1);
        for(int i=0; i<M; i++)
            x1[i] -= x2[i];
        return x1;
    }

    void add(int idx,int j, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx][j] += delta;
    }
};

FenwickTree ft;
vector<vector<int> >adj;
int n,q;
int a[N];
vector<int> parent, depth, heavy, head, pos;

struct HLD
{
    int cur_pos;
    int dfs(int v)
    {
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v])
        {
            if (c != parent[v])
            {
                parent[c] = v, depth[c] = depth[v] + 1;
                int c_size = dfs(c);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[v] = c;
            }
        }
        return size;
    }

    void decompose(int v, int h)
    {
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (int c : adj[v])
        {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c);
        }
    }

    void init()
    {
        int n = adj.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        cur_pos = 0;
        dfs(0);
        decompose(0, 0);
        for(int i=0; i<n; i++)
        {
            ft.add(pos[i], a[i], 1);
        }
    }

    int query(int a, int b)
    {
        array<int,M>ret;
        fill(ret.begin(),ret.end(),0);
        for (; head[a] != head[b]; b = parent[head[b]])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            array<int,M>now = ft.sum(pos[head[b]], pos[b]);
            for(int j=0; j<M; j++)
                ret[j]+= now[j];
        }
        if (depth[a] > depth[b])
            swap(a, b);
        array<int,M>now = ft.sum(pos[a], pos[b]);
        int last = -1;
        for(int j=0; j<M; j++)
        {
            ret[j]+= now[j];
            if(!ret[j])
                continue;
            if(last==-1)
                last = ret[j];
            else if(ret[j]!=last)
            {
                return 0;
            }
        }

        return 1;
    }
    void update(int a, int idx,  int x)
    {
        ft.add(pos[a],idx,x);
    }
};

int getNum(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return ch-'a';
    if(ch>='A' && ch<='Z')
        return 26+ch-'A';
    return 52 + ch-'0';
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        a[i] = getNum(s[i]);
    }
    adj.resize(n);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD hld;
    ft.init(n);
    hld.init();

    string tmp;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            if(hld.query(u,v))
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
        else
        {
            int u;
            cin>>u>>tmp;
            u--;
            hld.update(u,a[u],-1);
            a[u] = getNum(tmp[0]);
            hld.update(u,a[u],1);
        }
    }
    return 0;
}
