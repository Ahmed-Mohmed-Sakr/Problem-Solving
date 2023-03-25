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


void solve() {

    int n, m, s, t, a, b, w;
    cin >> n >> m >> s >> t;


    vector<pair<int, int>> adj[n + 5];


    for (int i = 0; i < m; i++) {

        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});

    }

    int dis[n + 5];
    bool vis[n + 5];

    for (int i = 0; i <= n; i++) {
        dis[i] = inf;
        vis[i] = 0;
    }

    priority_queue<pair<int, int>> pq;
    dis[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int a = pq.top().second;
        pq.pop();

        if (vis[a]) continue;
        vis[a] = 1;

        for (auto u: adj[a]) {
            int b = u.first, w = u.second;

            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                pq.push({-1 * dis[b], b});
            }
        }

    }
    if (dis[t] == inf) cout << "unreachable\n";
    else
        cout << dis[t] << "\n";


}

int main() {
    FAST

    int t; cin>>t;
    int c=1;
    while (t--){
        cout<<"Case #"<<c<<": ";
        solve();
        c++;
        //cout<<"\n";
    }


}

