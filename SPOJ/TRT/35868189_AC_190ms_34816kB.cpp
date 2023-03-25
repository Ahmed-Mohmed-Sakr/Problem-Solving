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
vector<int> arr;

int dp[2005][2005];

int solve(int l,int r,int days) {

    if (l > r) {
        return 0;
    }

    int &ans = dp[l][r];
    if(ans!=-1) return ans;

    ans = max(days * arr[l] + solve(l + 1, r, days + 1),
                  days * arr[r] + solve(l, r - 1, days + 1));

    return ans;
}

void solveit() {

    cin>>n;
    arr=vector<int>(n+2);
    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<solve(0,n-1,1);

}

int32_t main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}