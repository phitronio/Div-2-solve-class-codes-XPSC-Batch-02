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
const int N = 2e5 +5;
typedef pair<int,int> pii;

struct FenwickTree
{
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) // a[l] + a[l+1] + a[l+2] + ... + a[r] // O(logn)
    {
		if(l>r)
			return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) // a[idx] += delta //O(logn)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


void TEST_CASES()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int> canWin (n);
    FenwickTree ft1(n+1); // canWin
    FenwickTree ft2(n+1); // which elements are found till now
    for(int i=0; i<n; i++) // O(n)
    {
        // a[i] -> 0 .. a[i]-1
        int win = ft1.sum(0,a[i]-1); //O(logn)
        // total move - win
        int lose = ft2.sum(0,a[i]-1)-win; //O(logn)

        ft2.add(a[i] , 1);
        if(win==0 && lose==0)
        {
            canWin[i] = 1;
        }
        else if(lose)
        {
            canWin[i] = 1;
        }
        else
        {
            canWin[i] = 0;
        }
        ft1.add(a[i] , canWin[i]); //O(logn)
    }
    // O(n logn)
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(canWin[i]==0)
            ans++;
    }
    cout<<ans<<"\n";
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
