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

int n;

vector<int> arr;

vector<vector<int>> dp;

int solve(int i,int prev) {
    if(i == n) return 0;

    int &ans= dp[i][prev];
    if(ans!=-1) return ans;

    ans = -100;
    if(arr[i]> prev) ans = max(ans,1+ solve(i+1,arr[i]));
    ans = max(ans,solve(i+1,prev));

    return  ans;

}

int32_t main() {
    Sakr_

    cin>>n;

    dp = vector<vector<int>> (n+1,vector<int>(n*2+1,-1));
    arr = vector<int>(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<solve(0,0);

    return 0;
}