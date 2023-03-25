#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
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
    static bool check_prime(int n) { bool is_prime = true;
        if (n == 0 || n == 1) {is_prime = false;}
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {is_prime = false;break;}}
        return is_prime;}
};

string s,t;
int n,m;

int dp[3008][3008];

int solve(int i,int j) {
    if (i == n || j == m) return 0;


    int &ans = dp[i][j];
    if (ans != -1) return ans;

    ans = 0;
    if (s[i] == t[j]) ans = max(ans, 1 + solve(i + 1, j + 1));

    ans = max(ans, solve(i + 1, j));
    ans = max(ans, solve(i, j + 1));

    return ans;

}


void buildout(int i,int j) {
    if (i == n || j == m) return;


    int ans = dp[i][j];


    if (ans == solve(i + 1, j)) {
        buildout(i + 1, j);
        return;
    }

    if (ans == solve(i, j + 1)) {
        buildout(i, j + 1);
        return;
    }

    if (s[i] == t[j]) {
        if (ans == 1 + solve(i + 1, j + 1)) {
            cout << s[i];
            buildout(i + 1, j + 1);
        }
    }

}

void solveit() {

    cin>>s>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof dp);

    solve(0,0);
    buildout(0,0);
}

int32_t main() {
    Sakr_

    //////////freopen("garden.in","r",stdin);
    int timeOfRepeteLoop = 1;
    ///cin>>timeOfRepeteLoop;
    while (timeOfRepeteLoop--) {
        solveit();
    }

}


