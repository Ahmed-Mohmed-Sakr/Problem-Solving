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

int v1,v2,t,d;

int dp[5000][100];
int solve(int speed , int i) {

    if(i==(t-1)) {
        if (speed != v2) return -1e8;
        return 0;
    }

    int &ans = dp[speed+2000][i];

    if(ans !=-1) return ans;

    ans = solve(speed,i+1) +speed;
    for(int j=1;j<=d;j++) {
        ans = max(ans,
                  max(solve(speed - j, i + 1) + speed - j,
                      solve(speed + j, i + 1) + speed + j));
    }
    return ans;
}

void solveit() {

    cin>>v1>>v2>>t>>d;

    memset(dp,-1,sizeof dp);
    cout<<solve(v1,0)+v1;

}

int main() {
    Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}