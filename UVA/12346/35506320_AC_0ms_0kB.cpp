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

int n,m;
int fi[22],ci[22];
ll v,t;

map<pair<ll,ll>,ll> dp;

ll solve(int i,ll cost,ll water) {
    if(i== n) {
        if(water*t >= v) return cost;
        return 1e9;
    }

    if(dp.count({i,water})) {
        return dp[{i,water}];
    }

    ll &ans=dp[{i,water}];
    ans =1e9;
    ans = min(ans,solve(i+1,cost+ci[i],water+fi[i]));
    ans = min(ans, solve(i+1,cost , water));

    return ans;
}


void solveit() {

    int i;
    cin>>n;

    for(i=0;i<n;i++) {
        cin>>fi[i]>>ci[i];
    }
    cin>>m;
    for(i=1;i<=m;i++) {
        dp.clear();
        cin>>v>>t;
        ll ans = solve(0,0,0);
        cout<<"Case "<<i<<": ";
        if(ans == int(1e9))
            cout<<"IMPOSSIBLE\n";
        else
            cout<<solve(0,0,0)<<"\n";
    }

}

int main() {
    Sakr_

    int t = 1;
    ///cin>>t;
    while (t--) {
        solveit();
    }

}