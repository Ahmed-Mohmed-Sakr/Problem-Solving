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

int c,n1,n5,n10;

int dp[60][105][505];

int solve(int i,int a,int b,int f) {

    if(i==c) {
        return 0;
    }

    int &ans=dp[a][b][f];

    if(ans!=-1) return ans;

    ans =1e9;
    if(a>=1) {
        ans = min(ans,1+ solve(i+1,a-1,b,f+2));
    }

    if(b>=2) {
        ans = min(ans,2+ solve(i+1,a,b-2,f+2));
    }

    if(b>=1 && f>=3) {
        ans = min(ans ,4+ solve(i+1,a,b-1,f-3));
    }

    if(f>=8) {
        ans = min(ans,8+ solve(i+1,a,b,f-8));
    }

    if (f>= 3 && a>= 1 ) {
        ans = min(ans , 4+solve(i + 1, a-1, b+1, f-3));
    }
    return ans;
}

void solveit() {

    cin>>c>>n1>>n5>>n10;

    memset(dp,-1,sizeof dp);
    cout<<solve(0,n10,n5,n1)<<"\n";


}

int main() {
    Sakr_

    int t = 1;
    cin>>t;
    while (t--) {
        solveit();
    }

}