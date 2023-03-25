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


int n,a;
const int x= 1e5 +5;
ll fr[x];
ll dp[x];

ll solve(ll i) {

    if(i>=x) {
        return 0;
    }

    ll &ans= dp[i];

    if(ans != -1) return ans;

    ans=-100;
    ans = max(ans, solve(i+2) + fr[i]*i );
    ans = max(ans, solve(i+1));
    //cout<<ans<<"\n";
    return ans;
}

int32_t main() {
    Sakr_

    cin>>n;

    for(int i=0;i<n;i++) {
        cin>>a;
        fr[a]++;
    }
    memset(dp,-1,sizeof dp);

    cout<<solve(0);

    return 0;
}