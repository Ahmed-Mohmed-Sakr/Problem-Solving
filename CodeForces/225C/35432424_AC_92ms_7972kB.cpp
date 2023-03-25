#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
#define pi 3.14159265
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;
#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif
  __builtin_popcountll();
*/
bool isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

int n,m,x,y;
vector<int> arr;
/// . ==> white
/// # ==> black

int dp[1005][1005][2];

int solve(int i,int width,int prev) {

    if(i==m) {
        if(width >=x && width <= y) return 0;
        else return 1e9;
    }

    /// 1 ==> white . so i take  arr[i] for all white
    /// 0==> black # so  i take n-arr[i] for all black

    int &ans=dp[i][width][prev];

    if(ans!=-1) return ans;

    ans = 1e9;
    if(width<y) {
        if(prev == 1) {
            ans = min(ans,arr[i]+ solve(i+1,width+1,prev));
        } else {
            ans = min(ans,(n-arr[i])+ solve(i+1,width+1,prev));
        }
    }

    if(width>=x) {
        if(prev == 1) {
            ///revarce here to take black
            ans = min(ans,(n-arr[i])+ solve(i+1,1,0));
        } else {
            ///revarce here to take white
            ans = min(ans,arr[i]+ solve(i+1,1,1));
        }
    }

    return ans;
}

int main() {
    Sakr_

    int i,j;
    char c;

    cin>>n>>m>>x>>y;

    arr = vector<int>(m,0);

    memset(dp,-1,sizeof dp);

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin>>c;
            if(c=='#') arr[j]++;
        }
    }

    cout<<min(solve(0,0,1), solve(0,0,0));

}