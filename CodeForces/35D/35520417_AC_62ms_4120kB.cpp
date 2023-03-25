#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
#define pi 3.14159265
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;

  __builtin_popcountll();
*/

int n,x;
int arr[105];

int dp[105][(int)1e4+5];

int solve(int i,int food) {

    if(i==n) return 0;

    int &ans = dp[i][food];

    if(ans!=-1) return ans;

    ans = -100;

    if(food >=((n-i) * arr[i])) ans = max(ans,1+solve(i+1,food - ((n-i) * arr[i])));

    ans = max(ans, solve(i+1,food));

    return ans;

}

void solveit() {

    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(0,x);
}

int main() {
    Sakr_

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }

}