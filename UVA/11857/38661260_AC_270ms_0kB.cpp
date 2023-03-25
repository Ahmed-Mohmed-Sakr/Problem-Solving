/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)1e5+5;

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
pair<int,int> minimumSpanningTree(vector<tuple<int,int,int>> &edges) {
    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);
    int ans = 0,a,b,weight,l=0;
    for (auto e: edges) {

        tie(weight,a,b) = e;


        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
            ans=max(ans , weight);
            l++;
        }
    }
    return {ans,l};
}


int main() {
    FAST

    int n,m,w,a,b;

    while (cin>>n>>m) {
        if(n==0 && m==0) break;

        vector<tuple<int,int,int>> arr;

        for(int i=0;i<m;i++) {
            cin>>a>>b>>w;
            arr.push_back({w,a,b});
        }

        auto ans = minimumSpanningTree(arr);

        if(ans.second == (n-1)) cout<<ans.first<<"\n";
        else cout<<"IMPOSSIBLE\n";

        arr.clear();

    }

}

