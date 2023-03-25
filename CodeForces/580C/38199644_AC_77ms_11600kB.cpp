/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N=(int)1e5+5;

int n,m;
vector<int> adj[N];
int arr[N];
int vis[N];
int dfs(int node, int cnt) {

    if(arr[node])cnt++; else cnt=0;

    vis[node]=1;

    if(cnt>m) return 0;
    if(adj[node].size()==1 && node!=1) return 1;

    int ans =0;
    for(auto ch:adj[node]) {
        if(!vis[ch]) {
            ans+=dfs(ch,cnt);
        }
    }
    return ans;
}
int main() {
    fast();

    int a, b;

    cin >> n >> m;

    for(int i=1;i<=n;i++) cin>>arr[i];

    for (int i = 0; i < (n-1); i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<dfs(1,0);

}