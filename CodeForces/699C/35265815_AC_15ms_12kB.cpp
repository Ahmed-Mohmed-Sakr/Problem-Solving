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
  __builtin_popcount();
*/
bool isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

int n;
int arr[105];
int dp[105][5];

int solve(int i, int prev) {
    if(i==n) {
        return 0;
    }

    int &ans = dp[i][prev];

    if(ans!=-1) return ans;

    ans=1e9;

    if(arr[i]==0)
        ans = min(ans, 1+solve(i+1,0));
    else if(arr[i]==1) {
        if(prev!=1) {
            ans=min(ans, solve(i+1,1));
        } else {
            ans = min(ans, 1+solve(i+1,0));
        }
    } else if(arr[i]==2) {
        if(prev!=2) {
            ans=min(ans, solve(i+1,2));
        } else {
            ans = min(ans, 1+solve(i+1,0));
        }
    } else {
        if(prev==0) {
            ans=min(ans, solve(i+1,1));
            ans = min(ans, solve(i+1,2));
        }
        else if(prev!=1) {
            ans=min(ans, solve(i+1,1));
        } else if(prev!=2) {
            ans = min(ans, solve(i+1,2));
        }
    }

    return ans;
}

int main() {
    Sakr_

    memset(dp,-1, sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<solve(0,0);

    return 0;
}