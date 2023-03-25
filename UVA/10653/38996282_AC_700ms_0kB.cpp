/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

const int N= (int)1e4+9;

int c,r;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool valid(int a,int b) {
    return (a>=0 && a<r && b>=0 && b<c);
}

void solve() {

    int a, b, w,rn,cn;
    int row,col;

    while (cin>>r>>c) {

        if (c == 0 && r == 0) return;

        bool grid[r + 2][c + 2];
        int dis[r + 2][c + 2];
        bool vis[r + 2][c + 2];
        memset(grid, 1, sizeof grid);
        cin >> row;
        while (row--) {
            cin >> rn >> cn;
            while (cn--) {
                cin >> col;
                grid[rn][col] = 0;
            }
        }

        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; ++j) {
                dis[i][j] = inf;
                vis[i][j] = 0;
            }
        }

        pair<int, int> s, d;
        cin >> s.first >> s.second;
        cin >> d.first >> d.second;

        priority_queue<tuple<int, int, int>> pq;
        dis[s.first][s.second] = 0;
        pq.push({0, s.first, s.second});

        while (!pq.empty()) {
            int ro = get<1>(pq.top());
            int co = get<2>(pq.top());
            pq.pop();

            if (vis[ro][co]) continue;
            vis[ro][co] = 1;

            for (int i = 0; i < 4; i++) {
                int n1 = ro + dx[i];
                int n2 = co + dy[i];
                if (valid(n1, n2) && grid[n1][n2]) {

                    if (dis[ro][co] + 1 < dis[n1][n2]) {
                        dis[n1][n2] = dis[ro][co] + 1;
                        pq.push({-1 * dis[n1][n2], n1, n2});
                    }

                }
            }

        }

        cout<<dis[d.first][d.second]<<"\n";
    }


}

int main() {
    FAST

    int t = 1;
    while (t--) {
        solve();
    }

}

