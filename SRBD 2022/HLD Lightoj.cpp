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
const ll mod = 1e9+7;
typedef pair<int,int> pii;


struct info
{
    ll sum= 0;
};

struct segtree
{
    int n;
    vector<info>t;

    void init(int n,vector<ll>&a)
    {
        t.clear();
        this->n = n;
        t.resize(n*4);
        build(1,0,n-1,a);
    }
    void Merge(info &node, info &l, info &r)
    {
        node.sum = l.sum + r.sum;
    }
    void build(int node, int l,int r,vector<ll>&a)
    {
        if(l==r)
        {
            t[node].sum = a[l];
            return;
        }
        int mid= (l+r)/2;
        build(node*2, l, mid,a);
        build(node *2 +1, mid+1, r,a);
        Merge(t[node], t[node*2], t[node *2+1]);
    }

    void update(int node, int l,int r, int i, int j, ll add)
    {
        if(l>j || r<i)
        {
            return;
        }
        if(l>=i && r<=j)
        {
            t[node].sum = add;
            return;
        }
        int mid = (l+r)/2;
        update(node *2, l,mid, i, j, add);
        update(node *2 +1, mid+1, r, i, j, add);
        Merge(t[node], t[node *2], t[node*2+1]);
    }
    void update(int l,int r, ll add)
    {
        update(1,0,n-1,l,r,add);
    }
    ll query(int node, int l, int r, int i, int j)
    {
        if(l>j || r<i)
        {
            return 0;
        }
        if(l>=i && r<=j)
        {
            return t[node].sum;
        }
        int mid = (l+r)/2;
        ll x = query(node *2, l,mid, i, j);
        ll y = query(node *2 +1, mid+1, r, i, j);
        return x+y;
    }
    ll query(int l, int r)
    {
        ll ret = query(1,0,n-1,l,r);
        return ret;
    }
    void show()
    {
        for(int i=0; i<n; i++)
        {
            cout<<query(1,0,n-1,i,i)<<" ";
        }
        cout<<endl;
    }
};

struct HLD
{
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    segtree seg;
    int dfs(int v, vector<vector<int>> const& adj)
    {
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v])
        {
            if (c != parent[v])
            {
                parent[c] = v, depth[c] = depth[v] + 1;
                int c_size = dfs(c, adj);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[v] = c;
            }
        }
        return size;
    }

    void decompose(int v, int h, vector<vector<int>> const& adj)
    {
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h, adj);
        for (int c : adj[v])
        {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c, adj);
        }
    }

    void init(vector<vector<int>> const& adj, vector<ll>&a)
    {
        int n = adj.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        cur_pos = 0;

        dfs(0, adj);
        decompose(0, 0, adj);
        vector<ll>tmp(n);
        for(int i=0; i<n; i++)
        {
            tmp[pos[i]] = a[i];
        }
        seg.init(n,tmp);
    }
    ll query(int a, int b)
    {
        ll res = 0;
        for (; head[a] != head[b]; b = parent[head[b]])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            ll cur_heavy_path_sum = seg.query(pos[head[b]], pos[b]);
            res +=  cur_heavy_path_sum;
        }
        if (depth[a] > depth[b])
            swap(a, b);
        ll last_heavy_path_sum = seg.query(pos[a], pos[b]);
        res += last_heavy_path_sum;
        return res;
    }
    void update(int a, int b, ll x)
    {
        for (; head[a] != head[b]; b = parent[head[b]])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            seg.update(pos[head[b]], pos[b], x);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        seg.update(pos[a], pos[b],x);
    }
};

HLD hld;
vector<vector<int> >adj;
vector<ll>a;
int n;

void TEST_CASES(int cas)
{
    adj.clear();
    a.clear();
    scanf("%d",&n);
    adj.resize(n);
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    hld.init(adj,a);
    int q;
    scanf("%d",&q);
    printf("Case %d:\n",cas);
    while(q--)
    {
        int f;
        scanf("%d",&f);
        if(f==0)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%lld\n",hld.query(u,v));
        }
        else
        {
            int u,v;
            scanf("%d %d",&u,&v);
            hld.update(u,u,(ll)v);
        }
    }

}

int main()
{
    int t=1,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        TEST_CASES(++cas);
    }
    return 0;
}

