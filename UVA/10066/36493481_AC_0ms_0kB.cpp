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

int n1,n2;
int a[105],b[105];

int dp[105][105];

int solve(int i,int j) {

    if (i == n1 || j == n2) return 0;


    int &ans = dp[i][j];
    if(ans!=-1) return ans;

    ans = -oo;
    if (a[i] == b[j]) {
        ans = max(ans, 1 + solve(i + 1, j + 1));
    } else {
        ans = max(ans, solve(i + 1, j));
        ans = max(ans, solve(i, j + 1));
    }
    return ans;
}

void solveit() {

    int i;
    int c=1;

    while (cin>>n1>>n2 && (n1!=0 && n2!=0)) {

        for(i=0;i<n1;i++) cin>>a[i];

        for(i=0;i<n2;i++) cin>>b[i];

        memset(dp,-1,sizeof dp);

        cout<<"Twin Towers #"<<c<<"\n";
        cout<<"Number of Tiles : "<<solve(0,0)<<"\n\n";
        c++;

    }

}

int32_t main() {
    Sakr_

    int timeOfRepeteLoop = 1;
    /////cin>>timeOfRepeteLoop;
    while (timeOfRepeteLoop--) {
        solveit();
    }

}