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

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void solve() {

    int n,e,t,m,a,b,w;

    cin>>n>>e>>t>>m;

    vector<pair<int,int>> adj[n+2];

    for(int i=0;i<m;i++) {
        cin>>a>>b>>w;
        adj[b].push_back({a,w});
    }

    int vis[n+2];
    int dis[n+2];
    priority_queue<pair<int,int>> pq;

    for(int i=0;i<=n;i++) {
        dis[i]=inf;
        vis[i]=0;
    }

    dis[e]=0;
    pq.push({0,e});

    while (!pq.empty()){

        a = pq.top().second; pq.pop();

        if(vis[a]) continue;
        vis[a]=1;

        for(auto u:adj[a]) {
            b=u.first;
            w=u.second;

            if(dis[a]+w < dis[b]) {
                dis[b]=dis[a]+w;
                pq.push({-1*dis[b],b});
            }
        }

    }

    int ans=0;
    for(int i=1;i<=n;i++) {
        if(dis[i]<=t) ans++;
    }

    cout<<ans<<"\n";

}

int main() {
    FAST

    int t = 1;
    cin>>t;
    while (t--) {
        solve();
        if(t!=0) cout<<"\n";
    }

}

