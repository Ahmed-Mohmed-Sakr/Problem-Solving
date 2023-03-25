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
vector<int> dp;

int solve(int i) {

    if(i >=n-1) return 0;

    int &ans = dp[i];
    if(ans != -1) return ans;

    ans =1e9;

    for(int x=1;x<=k;x++) {
        if(i+x<n) ans = min(ans, abs(arr[i] - arr[i+x]) + solve(i+x));
    }

    return ans;

}


int main() {
    Sakr_

    cin>>n>>k;


    arr=  vector<int>(n+3,0);
    dp= vector<int>(n+2,-1);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<solve(0);

    return 0;
}