/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
void fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<string> arr;
bool vis[30][30];
int sum;

int dx[] ={-1,1,0,0,-1,1,-1,1};
int dy[] ={0,0,-1,1,-1,1,1,-1};

bool isvalid(int i,int j) {

    return (i>=0 && i < arr[0].size() && j >=0 && j<arr.size() && !vis[i][j] && arr[i][j]=='1');
}



void dfs(int i,int j) {
    vis[i][j]=1;
    sum++;

    for(int x=0;x<8;x++) {
        if(isvalid(i+dx[x],j+dy[x])) {
            dfs(i+dx[x],j+dy[x]);
        }
    }

}

int main() {
    fast();

    int t;
    string s;
    cin>>t;

    getline(cin,s);
    getline(cin,s);
    while (t--) {

        sum=0;
        int ans=0;
        while (getline(cin,s)) {
            if(s.length()==0) break;

            arr.push_back(s);
        }

        for(int i=0;i<arr.size();i++) {
            for(int j=0;j<arr[0].size();j++) {
                sum=0;
                if(isvalid(i,j)) {
                    dfs(i,j);
                    ans=max(sum,ans);
                }
            }
        }

        memset(vis,0, sizeof vis);
        arr.clear();

        cout<<ans<<"\n";

        if(t!=0) cout<<"\n";
    }


}