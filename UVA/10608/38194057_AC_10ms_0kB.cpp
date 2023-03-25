/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N=(int)3e4+5;

int n,m;
vector<int> adj[N];
int vis[N];
int cnt;

void dfs(int node) {
    vis[node]=1;
    cnt++;

    for(auto ch:adj[node]) {
        if(!vis[ch]) dfs(ch);
    }
}
int main() {
    fast();

    int a,b,t;
    cin>>t;
    while (t--) {

        cin>>n>>m;

        memset(adj,0,sizeof adj);
        memset(vis,0,sizeof vis);
        cnt=0;
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = 0;
        for(int i=1;i<=n;i++) {
            cnt=0;
            if(!vis[i]) dfs(i);

            ans=max(cnt,ans);
        }
        cout<<ans<<"\n";

    }


}