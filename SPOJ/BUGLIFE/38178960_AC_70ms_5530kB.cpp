/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> adj[(int)3e3];
int vis[(int)3e3];
bool can;
int a,b,t,n,m;
void dfs(int node, int gen) {

    vis[node]=gen;

    for(auto ch:adj[node]) {

        if(!vis[ch]) {
            if (vis[node] == 1)
                dfs(ch, 2);
            else
                dfs(ch, 1);

        } else if(vis[node] == vis[ch]) {
            can = false;
            return;
        }
    }

}

int main() {
    fast();

    cin>>t;
    int c=1;
    while (t--) {
        cin>>n>>m;

        memset(vis,0,sizeof vis);
        memset(adj,0,sizeof adj);
        can=1;

        for(int i=0;i<m;i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool ans = 1;

        for(int i=0;i<n;i++) {
            if (!vis[i + 1]) {
                dfs(i + 1, 1);
                ans = min(ans, can);
            }
        }

        if(ans) cout<<"Scenario #"<<c<<":\n"<<"No suspicious bugs found!\n";
        else cout<<"Scenario #"<<c<<":\n"<<"Suspicious bugs found!\n";
        
        c++;
    }

}