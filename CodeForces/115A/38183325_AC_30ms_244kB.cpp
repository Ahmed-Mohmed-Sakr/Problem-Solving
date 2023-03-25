/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N=(int)2e3+5;

int n,p;
vector<int> adj[N];
int vis[N];

int dfs(int node) {
    vis[node]=1;

    int res=0;
    for(auto ch:adj[node]) {
        if (!vis[ch])
            res = max(res, 1 + dfs(ch));
    }
    return res;
}

int main() {
    fast();

    cin>>n;

    vector<int> roots;
    for(int i=1;i<=n;i++) {
        cin>>p;
        if(p==-1)roots.push_back(i);
        else {
            adj[p].push_back(i);
        }
    }

    int ans = 0;

    for(int i=0;i<roots.size();i++) {

        ans = max(dfs(roots[i]),ans);
    }

    cout<<ans+1;

}