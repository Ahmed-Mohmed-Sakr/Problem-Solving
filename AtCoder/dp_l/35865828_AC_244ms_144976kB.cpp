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

int arr[3005];
int dp[3005][3005][2];
int solve(int l,int r,bool player) {

    if(l>r) {
        return 0;
    }

    int &ans =dp[l][r][player];
    if(ans!=-1) return ans;

    if(player == 0) {
        ans = max(arr[l] + solve(l + 1, r, !player),
                  arr[r] + solve(l, r - 1, !player));
    } else {
        ans = min(-arr[l] + solve(l + 1, r, !player),
                  -arr[r] + solve(l, r - 1, !player));
    }
    return ans;
}

void solveit() {

    memset(dp,-1,sizeof dp);

    int n,i;

    cin>>n;
    for(i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<solve(0,n-1,0);
}

int32_t main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}