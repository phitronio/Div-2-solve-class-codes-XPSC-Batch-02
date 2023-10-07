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
const int N = 1e6 +5;
typedef pair<ll,ll> pii;

struct FenwickTree {
    vector<ll> bit;
    int n;

    FenwickTree() {
        this->n = N;
        bit.assign(n, 0);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int cnt[N];
FenwickTree f1;
FenwickTree f2;

void update(int idx, int add)
{
    cnt[idx] += add;
    f1.add(idx, add);
    f2.add(idx , (ll)add*1ll*idx);
}


int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    while(1)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int n;
            cin>>n;
            update(n,1);
        }
        else if(t==2)
        {
            int m;
            cin>>m;
            if(cnt[m]==0)
            {
                cout<<"-1\n";
            }
            else{
                cout<<m<<"\n";
                update(m,-1);
            }
        }
        else if(t==3){
            int k;
            cin>>k;
            int low = 0, high = N-1;
            int ans = 0;
            int baki = 0;
            while(low <= high)
            {
                int mid = (low + high)/2;
                int koto = f1.sum(0,mid);
                if(koto <= k)
                {
                    ans = mid;
                    low = mid+1;
                    baki = k - koto;
                }
                else{
                    high = mid-1;
                }
            }
            ll lol =f2.sum(0,ans);
            lol += (ans+1)*1ll*baki;
            cout<<lol<<"\n";
        }
        else{
            break;
        }
    }
    return 0;
}
