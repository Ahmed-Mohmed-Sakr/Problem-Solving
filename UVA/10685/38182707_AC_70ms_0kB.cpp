/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int c,r;
string  a,b;
map<string,int> mp;
vector<int> adj[(int)5e3+5];
int vis[(int)5e3+5];
int cnt;
void dfs(int node) {

    vis[node]=1;
    cnt++;
    for(auto ch:adj[node]) {
        if(!vis[ch]) {
            dfs(ch);
        }
    }
}

int main() {
    fast();

    while (cin >> c >> r) {

        if (c == 0 && r == 0) break;

        mp.clear();
        memset(adj,0,sizeof adj);
        memset(vis,0,sizeof vis);

        string s;
        for (int i = 1; i <= c; i++) {
            cin >> s;
            mp[s] = i;
        }

        for (int i = 0; i < r; i++) {
            cin >> a >> b;
            adj[mp[a]].push_back(mp[b]);
            adj[mp[b]].push_back(mp[a]);
        }
        int ans = 1;
        for (int i = 1; i <= c; i++) {
            cnt=1;
            if(vis[i]==0)
                dfs(i);

            ans=max(ans,cnt);
        }

        cout<<ans-1<<"\n";
    }


}