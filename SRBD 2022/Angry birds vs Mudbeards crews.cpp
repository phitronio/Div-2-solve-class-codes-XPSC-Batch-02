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
const int N = 100 +5;
typedef pair<int,int> pii;

vector<pii>dirs = {  {-1,0} , {1,0} , {0,-1} , {0,1} };
bool vis[N][N];
string s[N];
int n,m;
bool safe(int i, int j)
{
    return i>=0 && j>=0 && i<n && j<m;
}

void dfs(int x, int y)
{
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    for(auto it:dirs)
    {
        int i = it.first + x;
        int j = it.second + y;
        if(safe(i,j) && s[i][j]!='#')
            dfs(i,j);
    }
}

void TEST_CASES()
{
    memset(vis,0, sizeof vis);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    pii pos = {-1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='c')
            {
                for(auto it:dirs)
                {
                    int x = it.first + i;
                    int y = it.second + j;
                    if(!safe(x,y))
                        continue;
                    if(s[x][y]=='.')
                    {
                        s[x][y] = '#';
                    }
                }
            }
            if(s[i][j]=='t')
            {
                pos = {i,j};
            }
        }
    }
    assert(pos.first!=-1);
    dfs(pos.first,pos.second);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='b' && !vis[i][j])
            {
                cout<<"no\n";
                return;
            }
            if(s[i][j]=='c' && vis[i][j])
            {
                cout<<"no\n";
                return;
            }
        }
    }
    cout<<"yes\n";

}




/*
*/

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<cas<<": ";
        cas++;
        TEST_CASES();
    }
    return 0;
}
