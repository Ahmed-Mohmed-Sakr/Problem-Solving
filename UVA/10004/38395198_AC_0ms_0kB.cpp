/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)2e2+5;

vector<int> adj[N];
int col[N];

int n,m;
bool can;
void bfs(int node) {
    queue<int> q;
    col[node] = 1;
    q.push(node);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u: adj[s]) {
            if (col[u]!=-1) {
                if(col[u]==col[s]) {
                    can= false;
                    return;
                }
            } else {
                if(col[s]==1) {
                    col[u]=2;
                } else {
                    col[u]=1;
                }

                q.push(u);
            }


        }
    }
}

int main() {
    FAST

    while (cin>>n) {

        if(n==0)break;
        cin>>m;

        memset(col, -1, sizeof col);
        memset(adj,0,sizeof adj);
        can = true;

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        bfs(0);

        if(can) {
            cout<<"BICOLORABLE.\n";
        } else {
            cout<<"NOT BICOLORABLE.\n";
        }
    }
}
