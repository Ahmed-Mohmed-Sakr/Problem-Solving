#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
#define pi 3.14159265
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  __builtin_popcountll();
*/

int n,m;
const int N=5e3+5;
int arr[N] , dp[N][N];

int solve(int i,int stat) {
    if(i==n) return 0;

    int &ans = dp[i][stat];
    if(ans!=-1) return ans;

    ans = 1e9;

    if(stat == arr[i]) ans = min(ans, solve(i+1,stat));

    if(stat < arr[i]) ans = min(ans,min(1+solve(i+1,stat), solve(i+1,arr[i])));

    if(stat > arr[i]) ans = min(ans,1+ solve(i+1,stat));

    return ans;

}

void solveit() {

    double q;
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr[i]>>q;
    }
    cout<<solve(0,1);
}

int main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }

}