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

string s1,s2;
int a,b;
int dp[106][106];

int solve(int i,int j) {

    if (i == a || j == b) return 0;

    int &ans = dp[i][j];
    if(ans!=-1) return ans;

    ans=-100;
    if (s1[i] == s2[j])
        ans = 1 + solve(i + 1, j + 1);
    else {
        ans =  max(solve(i + 1, j),solve(i, j + 1));
    }

    return ans;

}

int main() {
    Sakr_

    int counter=1;
    while (getline(cin,s1)) {
        if(s1[0]=='#')break;
        getline(cin,s2);
        memset(dp,-1,sizeof dp);
        a=s1.length();
        b=s2.length();
        cout<<"Case #"<<counter<<": you can visit at most "<<solve(0,0)<<" cities."<<"\n";
        counter++;
    }

    return 0;
}