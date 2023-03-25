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

const int N= (int)2e3+9;


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

int n;

int grid[N][N];
vector<pair<int,int>> adj[N];
int vis[N];

int minimumSpanningTree(vector<tuple<int,int,int>> &edges) {


    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);

    int weight;
    int ans=0;
    int a,b;
    for (auto e: edges) {

        tie(weight,a,b) =e;

        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
           adj[a].push_back({b,weight});
           adj[b].push_back({a,weight});
           ans++;
        }
    }

    return ans;

}

bool check() {

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j && grid[i][j]) return false;
            if(grid[i][j] != grid[j][i]) return false;
        }
    }

    return true;
}
bool can;
int cur;
void dfs(int p,int sum) {

        if(grid[cur][p] != sum) {
            can= false;
            return;
        }


    vis[p]=1;

    for(auto ch:adj[p]) {

        if(!vis[ch.first]) {
            dfs(ch.first,sum+ch.second);
        }
    }

}

int main() {
    FAST
    cin>>n;

    vector<tuple<int,int,int>> arr;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>grid[i][j];
            if(grid[i][j]>0)
                arr.push_back({grid[i][j],i,j});
        }
    }

    if(!check()) {
        cout<<"NO";
        return 0;
    }

    int res = minimumSpanningTree(arr);

    if(res != (n-1)) {
        cout<<"NO";
        return 0;
    }

    for(int i=0;i<n;i++) {
        can= true;
        cur=i;

        memset(vis,0,sizeof vis);
        dfs(i,0);

        if(can== false) {
            cout<<"NO";
            return 0;
        }

    }

    cout<<"YES";



}

