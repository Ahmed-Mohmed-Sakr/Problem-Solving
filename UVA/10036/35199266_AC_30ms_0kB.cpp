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
int n,k;
vector<int> arr;
vector<vector<int>> dp;
bool solve(int i,int sum){
    if(i==n) {

        if(sum==0) return 1;

        return 0;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    return dp[i][sum] = ((solve(i+1,abs(sum+arr[i])%k)) || (solve(i+1,abs(sum-arr[i])%k)));



}

int32_t main() {
    Sakr_

    int t,i;
    cin>>t;

    while (t--) {
        cin>>n>>k;
        arr= vector<int>(n+2);
        dp = vector<vector<int>>(n+2,vector<int>(k+2,-1));

        for(i=0;i<n;i++) {
            cin>>arr[i];
        }
        cout<<(solve(1,arr[0]%k)?"Divisible\n":"Not divisible\n");

    }



    return 0;
}