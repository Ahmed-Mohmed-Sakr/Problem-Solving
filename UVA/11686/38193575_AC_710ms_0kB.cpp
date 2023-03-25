/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N=(int)1e6+5;

int n,m;
vector<int> adj[N];
vector<int> adjj[N];
int vis[N];
vector<int> ans;

bool mychild(int parent, int cch) {
    for(int ccch:adj[parent]) {
        if(ccch==cch)return true;
    }
    return false;
}


bool canmove(int ch) {
    for(int cch:adjj[ch]) {
        if(!vis[cch] && !mychild(ch,cch)) return false;
    }
    return true;
}
void dfs(int node) {
    vis[node]=1;
    ans.push_back(node);

    for(auto ch:adj[node]) {
        if(!vis[ch] && canmove(ch)) {

            dfs(ch);
        }
    }
}

int main() {
    fast();

    int a,b;
    while (cin>>n>>m){
        if(n==0&&m==0)break;

        memset(adj,0,sizeof adj);
        memset(adjj,0,sizeof adjj);
        memset(vis,0,sizeof vis);
        ans.clear();

        vector<int> roots(n+5,1);
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            adj[a].push_back(b);
            adjj[a].push_back(b);
            adjj[b].push_back(a);
            roots[b]=0;
        }

        for(int i=1;i<=n;i++) {
           if(roots[i] && !vis[i]) {
               dfs(i);
           }
        }

        if(ans.size()==n) {
            for(int i=0;i<n;i++) {
                cout<<ans[i]<<"\n";
            }
        } else {
            cout<<"IMPOSSIBLE\n";
        }


    }


}