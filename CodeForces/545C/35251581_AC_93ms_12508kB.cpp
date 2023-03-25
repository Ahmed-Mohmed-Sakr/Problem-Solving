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
const int N=1e5+5;
int n;
ll x[N],h[N];

int dp[N][4];
int solve(int i,ll prev,ll front,int stat) {
    if(i==n-1) {
        return 0;
    }

    int &ans = dp[i][stat];
    if(ans!=-1) return ans;
    ans=-100;

    //to left
    if(x[i]-h[i] > prev)
        ans=max(ans,1+ solve(i+1,x[i],x[i+2],2));
    //to right
    if(front > x[i]+h[i]) {
        ans = max(ans, 1 + solve(i + 1, x[i] + h[i], x[i + 2],3));
    }
    //don't cut it
    ans =max(ans, solve(i+1,x[i],x[i+2],1));

    return ans;
}

int32_t main() {
    Sakr_

    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x[i]>>h[i];
    }
    memset(dp,-1,sizeof dp);

    cout<<solve(0,-1e9-9,x[1],0)+1;

    return 0;
}