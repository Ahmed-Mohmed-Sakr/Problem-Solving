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

const int N=100+5;

char grid[N][N];
bool vis[N][N];
int n;

bool isvalid(int i,int j) {

    return (i>=0 && i < n && j >=0 && j<n && !vis[i][j] && grid[i][j]!='.');
}



void dfs(int i,int j) {
    vis[i][j]=1;

    for(int x=0;x<4;x++) {
        if(isvalid(i+dx[x],j+dy[x])) {
            grid[i+dx[x]][j+dy[x]]='.';
            dfs(i+dx[x],j+dy[x]);
        }
    }

}

int main() {
    fast();

    int t;cin>>t;
    int c=1;
    while (t--) {
        cin>>n;
        memset(grid,0,sizeof grid);
        memset(vis,0, sizeof vis);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j]&&grid[i][j]=='x') {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<"Case "<<c<<": "<<ans<<"\n";
        c++;
    }


}