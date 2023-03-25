#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
using namespace std;
/**
 * by:Ahmed Sakr (sakr_) with AZA ;
 * freopen("input.txt","r",stdin);
 * freopen("output.txt","w",stdout);
 * __builtin_popcountll();
**/


int n,l,k;
int d[505],a[505];
int dp[505][505];
int solve(int i,int rem) {

    if(i==n) {
        return 0;
    }

    int &ans = dp[i][rem];
    if(ans!=-1) return ans;

    ans = 1e9;
    for(int j=i+1; ((j - i-1) <= rem) && (j <=n) ; j++) {

        //////cout<<a[i]<<"  "<<d[j]<<"  "<<a[i]*d[j]<<"\n";

        ans = min(ans, (a[i] * (d[j] - d[i])) + solve(j, rem - (j - i - 1)));

    }

    /////cout<<ans<<"\n";
    return ans;
}


void solveit() {

    int i;
    cin>>n>>l>>k;

    for(i=0;i<n;i++) cin>>d[i];

    d[n]=l;

    for(i=0;i<n;i++) cin>>a[i];
/*
    for(i=0;i<n;i++) {
        if(i+1==n) {
            d[i]=l-d[i];
        } else {
            d[i]=d[i+1]-d[i];
        }
    }

    for(i=0;i<n;i++) cout<<d[i]<<" ";
    cout<<"\n";
*/
    memset(dp,-1,sizeof dp);
    cout<<solve(0,k);
}

int32_t main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}