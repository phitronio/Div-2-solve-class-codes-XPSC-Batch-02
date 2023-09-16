vector < vector<int> > g;
vector<bool> used;
vector<int> order;

void dfs (int v)
{
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs (g[v][i]);
    // returning
    order.push_back (v);
}

for(int i=0;i<n;i++)
{
    if(!used[i])
    {
        dfs (i);
    }
}

reverse(order.begin(),order.end());
