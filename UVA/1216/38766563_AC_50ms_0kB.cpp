/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

const int N= (int)2e6+9;


struct DSU {
    int par[N], sz[N];
    void init(int n) {
        for (int i = 0; i < n; i++) par[i] = i;
        for (int i = 0; i < n; i++) sz[i] = 1;
    }
    int find (int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }

    int count(int u) {
        return sz[find(u)];
    }
};

ll r;

ll minimumSpanningTree(vector<tuple<ll,int,int>> &edges) {


    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);

    ll weight;
    vector<ll> ans;
    int a,b;
    for (auto e: edges) {

        tie(weight,a,b) =e;

        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
           ans.push_back(weight);
           ///cout<<weight<<"\n";
        }
    }
    int n=ans.size()-r;

    //cout<<ans.size()<<"   "<<r<<"  "<<ans[n]<<"\n";


    return ans[n]+1;

}


int main() {
    FAST

    ll t,a,b; cin>>t;

    ///ll ma=-1;
    while (t--) {
        cin >> r;
        vector<pair<ll, ll>> arr;

        while (cin >> a) {
            if (a == -1) break;

            cin >> b;

            arr.push_back({a, b});
            ///ma=max(ma,max(a,b));
        }


        ll n = arr.size();

        vector<tuple<ll, int, int>> edges;
        for (ll i = 0; i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                ll l1 = (arr[i].first - arr[j].first);
                ll l2 = (arr[i].second - arr[j].second);

                ll len = sqrt((l1 * l1) + (l2 * l2));
                edges.push_back({len, i, j});
            }
        }

        auto res = minimumSpanningTree(edges);

        cout << res << "\n";
    }
}

