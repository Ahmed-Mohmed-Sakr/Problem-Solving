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

int h,w;
int arr[102][102];
int dp[102][102];
int solve (int i,int j) {
    if(i==h) {
        return 0;
    }

    int &a=dp[i][j];

    if(a!=-1) return a;

    a = -100;
    a= max(a, arr[i][j]+solve(i+1,j));
    if(j-1 >=0) a= max(a,arr[i][j] + solve(i+1,j-1));
    if(j+1<w) a= max(a, arr[i][j] + solve(i+1,j+1));

        return a;

}

int32_t main() {
    Sakr_

    int t,i,j;

    cin>>t;
    while (t--) {
        cin>>h>>w;
        for(i=0;i<h;i++) {
            for(j=0;j<w;j++) {
                cin>>arr[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        int ans = -100;
        for(j=0;j<w;j++) {
            ans = max(ans,solve(0,j));
        }
        cout<<ans<<"\n";
    }

    return 0;
}