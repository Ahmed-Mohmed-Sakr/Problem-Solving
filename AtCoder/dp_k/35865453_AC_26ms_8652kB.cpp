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

int n,k,arr[105];

int dp[100005];

bool solve(int r) {

    if(r<arr[0]) {
        return 0;
    }

    int &ans = dp[r];
    if(ans!=-1) return ans;

    ans = 0;

    for(int i=0;i<n;i++) {
        if(r>=arr[i]  && !solve(r-arr[i])) {
            ans = (ans || 1);
            break;
        }
    }
    return ans;
}

void solveit() {

    cin>>n>>k;

    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    bool ans  = solve(k);

    if(ans==1) cout<<"First";
    else cout<<"Second";

}

int32_t main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}