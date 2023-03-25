#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define int  long long
#define oo 1e15
using namespace std;
/**
 * by:Ahmed Sakr (sakr_) with AZA ;
 * freopen("input.txt","r",stdin);
 * freopen("output.txt","w",stdout);
 * __builtin_popcountll();
**/
class utility {

public :
    static int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
    static int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
};

int n,g,wd;

int p[1001],w[1001];

int dp[1001][33];

int solve(int i,int rem) {
    if(i==n) return 0;

    int &ans=dp[i][rem];
    if(ans!=-1) return ans;

    ans = -oo;

    ans = max(ans, solve(i+1,rem));

    if(rem>=w[i])
        ans = max(ans, solve(i+1,rem-w[i])+p[i]);

    return ans;

}


void solveit() {

    cin>>n;

    for(int i=0;i<n;i++) cin>>p[i]>>w[i];

    memset(dp,-1,sizeof dp);

    int ans=0;
    cin>>g;
    for(int i=0;i<g;i++) {
        cin>>wd;
        ans+=(solve(0,wd));
    }

    cout<<ans<<"\n";


}

int32_t main() {
    Sakr_

    int timeOfRepeteLoop = 1;
    cin>>timeOfRepeteLoop;
    while (timeOfRepeteLoop--) {
        solveit();
    }

}