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
const int M = 30 +5;
const int mod = 1e9+7;
typedef pair<int,int> pii;

int dp[N][M][M];
inline int add(int x, int y)
{
    return (x+y>=mod ? x+y-mod : x+y);
}

inline int sub(int x, int y)
{
    return (x-y<0 ? x-y+mod : x-y);
}

inline int gun(int x, int y)
{
    return ((x*1ll*y)%mod);
}

int solve(int length,int Minus,int maxi)
{
    if(length==0)
        return 1;
    int &ret = dp[length][Minus][maxi];
    if(ret!=-1)
        return ret;
    int ans = solve(length-1,0,maxi); // + bosabo
    if(Minus+1<maxi)
        ans =add(ans, solve(length-1,Minus+1,maxi)); //- bosabo
    return ret = ans;
}

#define SZ 233333
const int MOD=1e9+7; //or any prime
ll qp(ll a,ll b)
{
    ll x=1;
    a%=MOD;
    while(b)
    {
        if(b&1)
            x=x*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return x;
}
namespace linear_seq
{
inline vector<int> BM(vector<int> x)
{
    //ls: (shortest) relation sequence (after filling zeroes) so far
    //cur: current relation sequence
    vector<int> ls,cur;
    //lf: the position of ls (t')
    //ld: delta of ls (v')
    int lf,ld;
    for(int i=0; i<int(x.size()); ++i)
    {
        ll t=0;
        //evaluate at position i
        for(int j=0; j<int(cur.size()); ++j)
            t=(t+x[i-j-1]*(ll)cur[j])%MOD;
        if((t-x[i])%MOD==0)
            continue; //good so far
        //first non-zero position
        if(!cur.size())
        {
            cur.resize(i+1);
            lf=i;
            ld=(t-x[i])%MOD;
            continue;
        }
        //cur=cur-c/ld*(x[i]-t)
        ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
        vector<int> c(i-lf-1); //add zeroes in front
        c.push_back(k);
        for(int j=0; j<int(ls.size()); ++j)
            c.push_back(-ls[j]*k%MOD);
        if(c.size()<cur.size())
            c.resize(cur.size());
        for(int j=0; j<int(cur.size()); ++j)
            c[j]=(c[j]+cur[j])%MOD;
        //if cur is better than ls, change ls to cur
        if(i-lf+(int)ls.size()>=(int)cur.size())
            ls=cur,lf=i,ld=(t-x[i])%MOD;
        cur=c;
    }
    for(int i=0; i<int(cur.size()); ++i)
        cur[i]=(cur[i]%MOD+MOD)%MOD;
    return cur;
}
int m; //length of recurrence
//a: first terms
//h: relation
ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];
//calculate p*q mod f
inline void mull(ll*p,ll*q)
{
    for(int i=0; i<m+m; ++i)
        t_[i]=0;
    for(int i=0; i<m; ++i)
        if(p[i])
            for(int j=0; j<m; ++j)
                t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
    for(int i=m+m-1; i>=m; --i)
        if(t_[i])
            //miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
            for(int j=m-1; ~j; --j)
                t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
    for(int i=0; i<m; ++i)
        p[i]=t_[i];
}
inline ll calc(ll K)
{
    for(int i=m; ~i; --i)
        s[i]=t[i]=0;
    //init
    s[0]=1;
    if(m!=1)
        t[1]=1;
    else
        t[0]=h[0];
    //binary-exponentiation
    while(K)
    {
        if(K&1)
            mull(s,t);
        mull(t,t);
        K>>=1;
    }
    ll su=0;
    for(int i=0; i<m; ++i)
        su=(su+s[i]*a[i])%MOD;
    return (su%MOD+MOD)%MOD;
}
inline int work(vector<int> x,ll n)
{
    if(n<int(x.size()))
        return x[n];
    vector<int> v=BM(x);
    m=v.size();
    if(!m)
        return 0;
    for(int i=0; i<m; ++i)
        h[i]=v[i],a[i]=x[i];
    return calc(n);
}
}
using linear_seq::work;


void TEST_CASES()
{
    int n,r;
    cin>>n>>r;
    if(r==1)
    {
        cout<<"1\n";
        return;
    }
    vector<int>v;
    for(int i=0;i<=80;i++)
    {
        v.push_back(solve(i,0,r));
    }
    cout<<work(v,n)<<"\n";
}




/*
*/

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    memset(dp,-1,sizeof dp);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<cas<<": ";
        cas++;
        TEST_CASES();
    }
    return 0;
}
