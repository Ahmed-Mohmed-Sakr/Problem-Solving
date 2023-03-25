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

    bool onezero=1;
    sort(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(N);
    int ans = 0,a,b,weight;
    //cout<<"my path here \n";
    for (auto e: edges) {

        tie(weight,a,b) = e;

        if(a==0 || b==0) {
            if(onezero) onezero=0;
            else continue;
        }

//        cout<<a<<"  "<<b<<"\n";
        if (dsu.find(a) != dsu.find(b)) {

           // cout<<a<<"  "<<b<<"\n";
            dsu.merge(a, b);
            ans+=weight;
        }
    }
    return ans;
}


int minLen(string &a,string &b) {

    int ans =0;

    for(int i=0;i<4;i++) {
        int x = (max(a[i],b[i])-min(a[i],b[i]));

        ans += (min(x,10-x));
    }

    return ans;
}

void test() {

    int n; cin>>n;

    vector<string> arr;
    arr.push_back("0000");

    string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        arr.push_back(s);
    }

    ///{w,i,j}
    vector<tuple<int,int,int>> grap;

    for(int i=0;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            grap.push_back({minLen(arr[i],arr[j]),i,j});
        }
    }

//    cout<<"my grap\n";
//    for(auto xx:grap) {
//        cout<<get<0>(xx)<<" "<<get<1>(xx)<<" "<<get<2>(xx)<<"\n";
//    }

//    cout<<"\n";

    auto res = minimumSpanningTree(grap);
    cout<<res<<"\n";


}

int main() {
    FAST

    int t;  cin>>t;

    while (t--) {
        test();
    }

}

