/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> adj[(int)3e2];
int vis[(int)3e2];
bool can;
void dfs(int node, int color) {

    vis[node]=color;

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

    int n,l,a,b;

    while (cin>>n) {
        if(n==0)break;
        cin>>l;

        memset(vis,0,sizeof vis);
        memset(adj,0,sizeof adj);
        can=1;

        for(int i=0;i<l;i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0,1);

        if(can) {
            cout<<"BICOLORABLE.\n";
        } else {
            cout<<"NOT BICOLORABLE.\n";
        }

    }

}