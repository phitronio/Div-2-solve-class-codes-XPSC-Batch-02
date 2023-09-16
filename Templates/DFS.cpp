vector < vector<int> > g;
vector<bool> used;

void dfs (int v)
{
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs (g[v][i]);
}
