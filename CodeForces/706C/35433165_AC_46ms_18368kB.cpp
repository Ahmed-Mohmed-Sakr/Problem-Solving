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

int const m=1e5+5;

int n;
int c[m];
string s[m];

ll dp[m][2];

ll solve(int i,int r) {

    if(i==n) return 0;

    ll &ans=dp[i][r];

    if(ans!=-1) return ans;

    ans = 1e14;
    if(i==0) {
        ans = min(ans, solve(i + 1, 0));
        ans = min(ans, c[i] + solve(i + 1, 1));
    } else {
        string prev = s[i - 1];
        if (r == 1) reverse(prev.begin(), prev.end());

        string x = s[i];
        string y = s[i];
        reverse(y.begin(), y.end());

        if (x >= prev) ans = min(ans, solve(i + 1, 0));
        if (y >= prev) ans =  min(ans, c[i] + solve(i + 1, 1));
    }
    return ans;
}


int main() {
    Sakr_
    int i;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(i=0;i<n;i++) cin>>c[i];
    for(i=0;i<n;i++) cin>>s[i];

    ll x=solve(0,0);

    if(x==(1e14)) cout<<-1;
    else cout<<x;

}