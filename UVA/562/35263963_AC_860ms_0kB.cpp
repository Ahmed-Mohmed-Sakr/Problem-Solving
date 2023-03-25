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

int n,m,sum;
int arr[105];
int dp[105][(int)1e6];

int solve(int i,int ssum) {
    if(i==m) {
        return abs((sum-ssum) - ssum);
    }

    int &ans = dp[i][ssum];
    if(ans!=-1) return ans;

    ans= 1e9;
    ans=min(ans, solve(i+1,ssum+arr[i]));
    ans=min(ans, solve(i+1,ssum));
    return ans;

}


int main() {
    Sakr_

    int i;

    cin>>n;
    while (n--) {
        cin>>m;
        memset(dp,-1, sizeof dp);
        sum=0;
        for(i=0;i<m;i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<solve(0,0)<<"\n";

    }


    return 0;
}