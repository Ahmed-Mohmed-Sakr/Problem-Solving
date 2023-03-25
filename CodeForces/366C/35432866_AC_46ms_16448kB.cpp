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
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

int const m= 1e9;

int n,k;
int a[105],b[105];

int dp[105][40000];

int solve(int i, int sum) {

    if(i==n) {
        if(sum ==0 ) return 0;

        return -m;
    }

    int &ans =dp[i][sum + 10000];
    if(ans!=-1)return ans;

    ans= -m;
    ans= max(ans,solve(i+1,sum));
    ans= max(ans, a[i]+solve(i+1,sum+(a[i]-k*b[i])));

    return ans;
}

int main() {
    Sakr_

    int i;
    cin>>n>>k;
    memset(dp,-1,sizeof dp);

    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];

    int x = solve(0,0);
    (x==0?cout<<-1:cout<<x);

}