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


int n,g;

int p[1005],w[1005],mw[105];

int dp[1005][35];


int solve(int i, int remender) {

    if(i==n) {
        return 0;
    }

    int &ans= dp[i][remender];

    if(ans!=-1) return ans;

    ans=-100;

    if(remender >= w[i]) ans=max(ans, p[i]+solve(i+1,remender-w[i]));

    ans=max(ans, solve(i+1,remender));

    return ans;

}


int32_t main() {
    Sakr_

    int t,i;

    cin>>t;
    while (t--) {
        cin>>n;
        for(i=0;i<n;i++) {
            cin>>p[i]>>w[i];
        }
        cin>>g;
        for(i=0;i<g;i++) {
            cin>>mw[i];
        }
        ll ans=0;
        memset(dp,-1,sizeof dp);
        for(i=0;i<g;i++) {
            ans+=solve(0,mw[i]);
        }

        cout<<ans<<"\n";
    }


    return 0;
}