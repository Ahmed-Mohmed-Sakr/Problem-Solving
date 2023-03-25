/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N=(int)1e2+5;

int n,m;
vector<int> adj[N];
int vis[N];
int cnt;

void dfs(int node) {
    vis[node]=1;
    cnt++;
    for(int ch:adj[node]) {
        if(!vis[ch]) {
            dfs(ch);
        }
    }

}

int main() {
    fast();

    int a,b;
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cnt=0;
    dfs(n);

    if(n==m && n==cnt) cout<<"FHTAGN!";
    else cout<<"NO";
}