/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> adj[(int)2e2];
bool vis[(int)2e2];
bool root[(int)2e2];

void dfs(int node) {
    cout << node << " ";
    vis[node] = 1;

    for (auto ch: adj[node]) {
        if (!vis[ch])
            dfs(ch);
    }
}

int main() {
    fast();

    int n,m,a,b;

    while (cin>>n>>m) {
        if(n==0 && m==0) break;

        memset(adj,0,sizeof adj);
        memset(vis,0,sizeof vis);
        memset(root,1,sizeof root);


        for(int i=0;i<m;i++) {
            cin>>a>>b;
            adj[a].push_back(b);
            root[b]=0;
        }

        for(int i=1;i<=n;i++) {
            if(root[i]) dfs(i);
        }
        cout<<"\n";

    }

}