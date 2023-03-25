/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)2e3+5;

int dis[N][N];

const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};

int n,m;

bool valid(int x, int y) {
    return  x>=0 && x<n && y>=0 && y<m;
}

int main() {
    FAST

    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;

    int k; cin>>k;

    int a,b;
    memset(dis,-1,sizeof dis);
    queue<pair<int,int>> q;

    for(int i=0;i<k;i++) {
        cin>>a>>b;
        dis[a-1][b-1]=0;
        q.push({a-1,b-1});
    }

    int ansx,ansy;
    while (!q.empty()) {

        tie(a,b)= q.front(); q.pop();
        ansx=a;
        ansy=b;
        for(int i=0;i<4;i++) {
            int x=a+dx[i];
            int y=b+dy[i];

            if(valid(x,y) && dis[x][y]==-1) {
                dis[x][y]=dis[a][b]+1;
                q.push({x,y});
            }
        }

    }

    cout<<ansx+1<<" "<<ansy+1;

}

