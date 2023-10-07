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

    int query(int a, int b)
    {
        ll res = 0;
        for (; head[a] != head[b]; b = parent[head[b]])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            int cur_heavy_path_max = seg.query(pos[head[b]], pos[b]);
            res +=  cur_heavy_path_max;
        }
        if (depth[a] > depth[b])
            swap(a, b);
        // if edge query then pos[a]+1
        int last_heavy_path_max = seg.query(pos[a], pos[b]);
        res += last_heavy_path_max;
        return res;
    }
    void update(int a, int b, int x)
    {
        for (; head[a] != head[b]; b = parent[head[b]])
        {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            seg.update(pos[head[b]], pos[b], x);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        // if edge update then pos[a]+1
        seg.update(pos[a], pos[b],x);
    }
};
