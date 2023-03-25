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

vector<tuple<int,int,int>> minimumSpanningTree(vector<tuple<int,int,int>> &edges) {


    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);

    vector<tuple<int,int,int>> ans;

    int weight;
    int a,b;
    for (auto e: edges) {

        tie(weight,a,b) = e;

        if (dsu.find(a) != dsu.find(b)) {
            dsu.merge(a, b);
            ans.push_back({a,b,weight});
        }
    }

    return ans;

}

void test() {

    int n;
    cin >> n;

    int x;
    char c;

    vector<tuple<int, int, int>> arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;

            if (j < n - 1) cin >> c;

            if (x > 0) {
                arr.push_back({x, i, j});
            }
        }
    }

    auto res = minimumSpanningTree(arr);

    for (auto ans: res) {
        cout << char(get<0>(ans) + 'A') << "-" << char(get<1>(ans) + 'A') << " " << get<2>(ans) << "\n";
    }

}

int main() {
    FAST

    int t; cin>>t;

    int c=1;
    while (t--) {
        cout<<"Case "<<c<<":\n";
        c++;
        test();
    }

}

