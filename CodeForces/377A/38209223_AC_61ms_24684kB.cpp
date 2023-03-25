/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int N=(int)5e2+5;

int n,m,k;
char grid[N][N];
int vis[N][N];
int cnt;
int stop;
int dx[] ={-1,1,0,0,-1,1,-1,1};
int dy[] ={0,0,-1,1,-1,1,1,-1};

bool isvalid(int i,int j) {
    return (i>=0 && i <n  && j >=0 && j<m && !vis[i][j] && grid[i][j]=='.');
}

void dfs(int i,int j) {
    vis[i][j]=1;
    cnt++;
    ///cout<<cnt<<" "<<stop<<"\n";
    if(cnt>stop) grid[i][j]='X';
    for(int x=0;x<4;x++) {
        if(isvalid(i+dx[x],j+dy[x])) {
            dfs(i+dx[x],j+dy[x]);
        }
    }

}

void makeDfsOneTime() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]=='.') {
                dfs(i,j);
                return;
            }
        }
    }
}

int main() {
    fast();

    cin>>n>>m>>k;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    cnt=0;
    stop=(int)1e9;
    makeDfsOneTime();
    memset(vis,0,sizeof vis);
    stop=cnt-k;
    cnt=0;
    makeDfsOneTime();

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

}