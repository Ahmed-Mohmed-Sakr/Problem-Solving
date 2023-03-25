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
vector<int> a,b,c;

vector<vector<int>>dp;


int solve(int i, int state) {

    if(i==n) return 0;

    int &ans= dp[i][state];

    if(ans!=-1) return ans;

    ans = -1e8;

    if(state !=1 ) ans = max(ans , a[i]+ solve(i+1,1));
    if(state !=2 ) ans = max(ans , b[i]+ solve(i+1,2));
    if(state !=3 ) ans = max(ans , c[i]+ solve(i+1,3));

    return  ans;

}


int main() {
    Sakr_

    cin>>n;

    a=b=c=vector<int>(n+2);

    dp = vector<vector<int>> (n+2,vector<int>(4,-1));
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i];
    }

    cout<<solve(0,0);

    return 0;
}