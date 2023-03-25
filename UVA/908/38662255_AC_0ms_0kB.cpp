/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)1e6+5;

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

// {weight, a, b}
int minimumSpanningTree(vector<tuple<int,int,int>> &edges) {
    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);
    int ans = 0,a,b,weight;
    for (auto e: edges) {

        tie(weight,a,b) = e;


        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
            ans+=weight;
        }
    }
    return ans;
}


int main() {
    FAST

    int n,m,w,a,b;
    int ans=0;
    
    bool end = 0;

    while (cin>>n) {

        if(end) cout<<"\n";

        ans=0;
        vector<tuple<int,int,int>> arr;
        for(int i=1;i<n;i++) {
            cin>>a>>b>>w;
            ans+=w;
        }

        cout<<ans<<"\n";

        int k; cin>>k;

        for(int i=0;i<k;i++) {
            cin>>a>>b>>w;
            arr.push_back({w,a,b});
        }

        int m; cin>>m;

        for(int i=0;i<m;i++) {
            cin>>a>>b>>w;
            arr.push_back({w,a,b});
        }

        auto res = minimumSpanningTree(arr);

        cout<<res<<"\n";

        end = 1;

    }

}

