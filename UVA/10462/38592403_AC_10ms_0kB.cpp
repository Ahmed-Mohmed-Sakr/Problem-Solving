/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)2e2+5;

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

// {weight, a, b,use or not}
vector<int> IsTheresASolutionUsingMinimumSpanningTree(vector<tuple<int,int,int,int>>&edges) {
    DSU dsu;
    dsu.init(N);
    vector<int> ans;
    int a,b,weight,index;
    for (auto e: edges) {
        tie(weight,a,b,index) = e;

        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
            ans.push_back(index);
        }
    }
    return ans;
}


// {weight, a, b,use or not}
pair<int,int> SecondminimumSpanningTree(vector<tuple<int,int,int,int>>&edges , int notused) {
    DSU dsu;
    dsu.init(N);
    int ans=0,edge=0,a,b,weight,index;
    for (auto e: edges) {
        tie(weight,a,b,index) = e;
        if (notused!=index && dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
            ans+=weight;
            edge++;
        }
    }

    pair<int,int> res={ans,edge};

    return res;
}

int main() {
    FAST

    int t;cin>>t;
    int n,m,a,b,w;
    int c=1;

    while (t--) {
        cin>>n>>m;
        vector<tuple<int,int,int,int>> edges;

        for(int i=0;i<m;i++) {
            cin>>a>>b>>w;
            edges.push_back({w,a,b,i});
        }

        sort(edges.begin(),edges.end());

        vector<int> ans = IsTheresASolutionUsingMinimumSpanningTree(edges);

        if(ans.size() != (n-1)) {
            cout<<"Case #"<<c<<" : No way\n";
        } else {
            int exist=inf;
            for(auto e:ans) {
                auto res = SecondminimumSpanningTree(edges, e);
                if(res.second == (n-1)) {
                    exist=min(exist,res.first);
                }
            }

            if(exist==inf) cout<<"Case #"<<c<<" : No second way"<<"\n";
            else cout<<"Case #"<<c<<" : "<<exist<<"\n";
        }
        c++;
    }


}

