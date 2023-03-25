#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define int  long long
using namespace std;
/**
 * by:Ahmed Sakr (sakr_) with AZA ;
 * freopen("input.txt","r",stdin);
 * freopen("output.txt","w",stdout);
 * __builtin_popcountll();
**/

int n,m,k;
int arr[5005],pr[5005];
int dp[5005][5005];
int solve(int i, int rage) {

    if(i>n) {
        if(rage !=0) return -1e8;
        return 0;
    }

    int &ans = dp[i][rage];

    if(ans!=-1) return ans;

    ans = solve(i+1,rage);
    if(rage>0 && i+m-1 <=n) {
        ans = max(ans, (pr[i+m-1] - pr[i-1])+solve(i+m,rage-1));
    }

    return ans;

}

void solveit() {

    cin>>n>>m>>k;

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    pr[0]=0;
    for(int i=1;i<=n;i++) {
        pr[i] = pr[i-1] + arr[i];
    }

    memset(dp,-1,sizeof dp);

    cout<<solve(1,k);

}

int32_t main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}