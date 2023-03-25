/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int dx[] ={-1,1,0,0,-1,1,-1,1};
int dy[] ={0,0,-1,1,-1,1,1,-1};

const int N=(int)5e4+5;
vector<int> adj[N];
int ans[N];
int vis[N];

int n,r1,r2;

void dfs(int node) {
    vis[node]=1;

    for(auto ch:adj[node]) {
        if(!vis[ch]) {
            ans[ch]=node;
            dfs(ch);
        }
    }
}

int main() {
    fast();

    int a;
    cin>>n>>r1>>r2;

    for(int i=1;i<=n;i++) {
        if(i!=r1) {
            cin>>a;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
    }

    dfs(r2);
    for(int i=1;i<=n;i++) {
        if(i!=r2) {
            cout<<ans[i]<<" ";
        }
    }

}