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
bool isPrime(int x) {
    if (x <= 1) return false;   if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6) if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

const int m=2e3+5;
int n;
int arr[m];

int dp[m][m][2];

int lis(int i,int prev,bool x) {

    if(i==n) return 0;

    int &ans = dp[i][prev][x];
    if(ans!=-1) return ans;

    ans =lis(i + 1 , prev , x);
    if(x == 1) {
        if (arr[i] > arr[prev]) {
            ans = max(ans, 1+lis(i+1,i,x));
        }
    } else {
        if (arr[i] < arr[prev]) {
            ans = max(ans, 1+lis(i+1,i,x));
        }
    }

    return ans;
}

void solveit() {

    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    memset(dp,-1,sizeof dp);

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = max( ans , 1+lis(i+1,i,1)+lis(i+1,i,0));
    }
    cout<<ans<<"\n";
}

int main() {
    Sakr_

    int t = 1;
    cin>>t;
    while (t--) {
        solveit();
    }

}