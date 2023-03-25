/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)1e5+5;

int n;
map<int,int> vis;
map<int,vector<int>> adj;

void dfs(int node) {

    vis[node]=1;

    cout<<node<<" ";

    for(auto ch:adj[node]) {
        if(!vis[ch]) {
            dfs(ch);
        }
    }

}

int main() {
    FAST
    cin>> n;

    int a,b;
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mp[a]++;
        mp[b]++;
    }

    int beginHere;

    for(auto m:mp) {
        if(m.second == 1) {
            beginHere = m.first;
            break;
        }
    }

    dfs(beginHere);

}
