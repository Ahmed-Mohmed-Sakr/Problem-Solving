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

int n,k;
vector<int> arr;
int dp[5005][5005];
int solve(int i,int rem) {

    if (i == n) {
        return 0;
    }

    int &ans = dp[i][rem];
    if (ans != -1)return ans;

    ans = solve(i + 1, rem);

    if (rem > 0) {
        int len = upper_bound(arr.begin(), arr.end(), arr[i] + 5) - arr.begin() - i;

        ans = max(ans, len + solve(i + len, rem - 1));
    }

}

void solveit() {

    cin>>n>>k;
    arr = vector<int>(n,0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

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