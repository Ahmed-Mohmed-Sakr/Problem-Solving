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

const int N= (int)1e2+9;


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

int n,m;

vector<tuple<int,int,int>> edges;

int minimumSpanningTree(int i) {


    ///sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);

    int mi=1e9,ma=-1e9,ans=0;

    int weight;
    int a,b;
    for (int j=i;j<m;j++) {

        tie(weight,a,b) = edges[j];

        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
            ans++;
            ma=max(weight,ma);
            mi=min( mi,weight);
        }
    }

    if(ans == (n-1)) return (ma-mi);
    return -1;

}

int main() {
    FAST

    int a,b,w;
    ////bool flag =0;
    while (cin>>n>>m) {
        if(n==0 && m==0) break;

        ///if(flag) cout<<"\n";

        edges.clear();

        for(int i=0;i<m;i++) {
            cin>>a>>b>>w;

            edges.push_back({w,a,b});
        }

        sort(edges.begin(), edges.end());

        int res= minimumSpanningTree(0);

        if(res ==-1) cout<<-1<<"\n";
        else {
            int ans = res;
            for(int i=1;i<m;i++) {
                res= minimumSpanningTree(i);
                if(res==-1) break;
                ans=min(ans,res);
            }
            cout<<ans<<"\n";
        }

        //flag=1;
    }

}

