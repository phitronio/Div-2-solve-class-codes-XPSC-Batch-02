#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v);
typedef pair<int,int> pii;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int a, int b)
{
    int x = uniform_int_distribution<int>(a, b)(rng);
    return x;
}


vector<int> getarray(int n,int a, int b);
void Print(vector<int>&v);
void gettree(int n,int one=1);
string getstring(int sz);

int main()
{
    freopen("input.txt","w",stdout);
    int t = 1;
    cout<<t<<"\n";
    while(t--)
    {
        int n = getrand(1,8);
        cout<<n<<"\n";
        vector<int>a = getarray(n,-10,100);
        cout<<a<<"\n";
    }
    return 0;
}
string getstring(int sz)
{
    string ret ="";
    for(int i=0; i<sz; i++)
    {
        ret += getrand(0,3)+'a';
    }
    return ret;
}

void gettree(int n, int one)//one = 1 for 1 indexed
{
    vector<int> p(n);
    for(int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = getrand(0,i-1);
    printf("%d\n", n);
    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end(),rng);
    vector<pair<int,int> > edges;
    for (int i = 1; i < n; i++)
        if (getrand(0,1))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));
    shuffle(edges.begin(), edges.end(),rng);
    for (int i = 0; i + 1 < n; i++)
        printf("%d %d\n", edges[i].first + one, edges[i].second + one);
}



vector<int> getarray(int n,int a, int b)
{
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {

        v[i] = getrand(a,b);

    }
    return v;
}

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<p.first<<" "<<p.second;
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    for(T i:v)
    {
        os<<i<<" ";
    }
    return os;
}
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v)
{
    for(auto i:v)
    {
        os<<"Key : "<<i.first<<" , Value : "<<i.second<<endl;
    }
    return os;
}
