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

int n;
int arr[405];
int pr[405];

int dp[405][405];
int solve(int l,int r) {

    if(l>=r) return 0;

    int &ans = dp[l][r];
    if(ans!=-1)return ans;

    ans = 1e18;
    for(int i=l;i<r;i++) {
        ans = min(ans ,(pr[r]-pr[l-1]) +solve(l,i)+ solve(i+1,r));
    }

    return ans;

}

void solveit() {

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    pr[0]=0;
    for(int i=1;i<=n;i++) {
        pr[i] = pr[i-1] + arr[i];
    }

    memset(dp,-1,sizeof dp);
    cout<<solve(1,n);

}

int32_t main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}