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

int dp[1005][1005];

int const mod = 1e9+7;

int main() {
    Sakr_

    int i,j,n,m;
    char c;
    cin>>n>>m;

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin>>c;
            if(c=='#') dp[i][j] =-1;
        }
    }

    for(int i=0;i<m;i++) {
        if(dp[0][i] != -1)
            dp[0][i] =1;
        else
            break;
    }

    for(int i=0;i<n;i++) {
        if(dp[i][0] != -1)
            dp[i][0] =1;
        else
            break;
    }

    for(i=1;i<n;i++) {
        for(j=1;j<m;j++) {
            if(dp[i][j] == -1)continue;
            int ans=0;
            if(dp[i - 1][j] != -1) ans= (ans+ dp[i - 1][j])%mod;
            if(dp[i][j - 1] != -1) ans= (ans+ dp[i][j - 1])%mod;
            dp[i][j] =ans;
        }
    }
/*
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cout<<dp[i][j]<<"  ";
        }
        cout<<"\n";
    }
*/
    cout<<dp[n-1][m-1];

}