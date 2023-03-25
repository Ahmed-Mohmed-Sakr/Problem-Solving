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

const int N= (int)1e4+9;


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

vector<pair<double,int>> adj[N];
int vis[N];

void minimumSpanningTree(vector<tuple<double,int,int>> &edges) {


    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);
    double ans = 1e9,weight;
    int a,b;
    for (auto e: edges) {

        tie(weight,a,b) = e;

        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);

            adj[a].push_back({weight,b});
            adj[b].push_back({weight,a});

            ///cout<<a<<"  "<<b<<"  "<<weight<<"\n";
        }
    }

}

double dfs(int node,double ma) {

    vis[node]=1;

    if(node == 1) return ma;

    double ans = 1e18;
    for(auto ch:adj[node]){

        if(!vis[ch.second]) {
            ans = min(ans,dfs(ch.second,max(ma,ch.first)));
        }

    }

    return ans;

}


int main() {
    FAST

    int n;
    double x,y,d;
    int c=1;

    while (cin>>n) {
        if(n==0) break;

        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++) {
            cin>>x>>y;
            arr.push_back({x,y});
        }

        vector<tuple<double,int,int>> resarr;
        memset(adj,0,sizeof adj);
        memset(vis,0,sizeof vis);

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                x=arr[j].first-arr[i].first;
                y=arr[j].second-arr[i].second;
                d= sqrt((x*x)+(y*y));
                resarr.push_back({d,i,j});
            }
        }

        minimumSpanningTree(resarr);

        auto res = dfs(0,0);

        cout<<"Scenario #"<<c<<"\n";
        cout<<"Frog Distance = "<<fixed<<setprecision(3)<<res<<"\n\n";

        c++;

    }

}

