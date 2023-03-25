/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)12;

//vector<int> adj[N];
int dis[N][N];

const int knightx[]={-2,-2,-1,1,2,2,-1,1};
const int knighty[]={-1,1,-2,-2,-1,1,2,2};

bool valid(int x,int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8 && dis[x][y]==-1);
}

int n,m;
int k,f;
bool can;
int bfs(int x,int y) {

    if (x == k && y == f) return 0;

    queue<pair<int, int>> q;
    dis[x][y] = 0;
    q.push({x, y});

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int t = a + knightx[i];
            int g = b + knighty[i];
            if (valid(t, g)) {
                dis[t][g] = dis[a][b] + 1;
                if (t == k && g == f) return dis[t][g];
                q.push({t, g});
            }
        }
    }

}

int main() {
    FAST

    string a,b;
    while (cin>>a>>b) {

        ///if(a=="0"&&b=="0")break;

        memset(dis,-1,sizeof dis);

        k=(b[1]-'1')+1;
        f=(b[0]-'a')+1;

        int moves= bfs((a[1]-'1')+1,(a[0]-'a')+1);

        cout<<"To get from "<<a<<" to "<<b<<" takes "<<moves<<" knight moves."<<"\n";


    }
}
