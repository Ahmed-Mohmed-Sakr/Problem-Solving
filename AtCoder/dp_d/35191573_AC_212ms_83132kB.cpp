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

int n,w;

vector<int> a,b;
vector<vector<int>> dp;
int solve(int i,int x) {

    if(i==n) return 0;

    int &ans = dp[i][x];

    if(ans!=-1) return ans;

    ans = -100;
    if(x - a[i] >=0) ans = max(ans , b[i]+ solve(i+1,x-a[i]));

    ans = max(ans ,solve(i+1,x));

    return ans;

}


int32_t main() {
    Sakr_

    cin>>n>>w;

    a=b=vector<int>(n);
    dp = vector<vector<int>>(n+1,vector<int>(w+1,-1));

    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
    }

    cout<<solve(0,w);

    return 0;
}