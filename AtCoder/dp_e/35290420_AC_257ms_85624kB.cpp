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
  __builtin_popcount();
*/
bool isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

#define int long long

int n,w,ma;

int a[105],b[105];
int dp[105][100005];
int solve(int i,int x) {

    if(i==n) {
      if(x==0) return 0;
      else return 1e9+100;
    }

    int &ans = dp[i][x];
    if(ans!=-1) return ans;

    ans = 1e9+9;
    if(b[i] <= x) ans = min(ans , a[i]+ solve(i+1,x-b[i]));

    ans = min(ans ,solve(i+1,x));

    return ans;

}


int32_t main() {
    Sakr_

    cin>>n>>w;
    ma=0;
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
        ma+=b[i];
    }
    memset(dp,-1,sizeof dp);

    for(int i= ma;i>=0;i--) {
        if(solve(0,i)<=w) {
            cout<<i;
            return 0;
        }
    }

    cout<<0;

    return 0;
}