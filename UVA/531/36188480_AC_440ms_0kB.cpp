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
};

vector<string > a,b;
string res;

int n,m;
int sizee;
int dp[3005][3005];

int solve(int i,int j) {

    if (i == n || j == m) return 0;

    int &ans = dp[i][j];
    if (ans != -1) return ans;


    ans =0;

    if (a[i] == b[j]) {
        ans = max(ans,solve(i + 1, j + 1) + 1);
    } else {
        ans = max(ans,max(solve(i + 1, j), solve(i, j + 1)));
    }

    return ans;
}

void buildAns(int i,int j) {

    if(i==n || j==m) return;

    if(a[i]==b[j]) {
        sizee--;
        if(sizee==0)
            res+=a[i];
        else
            res+= a[i]+" ";

        buildAns(i+1,j+1);
    } else if(dp[i+1][j]>dp[i][j+1]) {
        buildAns(i+1,j);
    } else {
        buildAns(i,j+1);
    }

}


void solveit() {


    string s;

    while (cin>>s) {

        a.clear(),b.clear(),res.clear();
        memset(dp,-1,sizeof dp);

        a.push_back(s);

        while (cin>>s) {
            if(s=="#") break;
            a.push_back(s);
        }

        while (cin>>s) {
            if(s=="#") break;
            b.push_back(s);
        }

        n=a.size();
        m=b.size();

        sizee = solve(0,0);
        buildAns(0,0);
        cout<<res<<"\n";

    }



}

int32_t main() {
    ////Sakr_

    int timeOfRepeteLoop = 1;
    /////cin>>timeOfRepeteLoop;
    while (timeOfRepeteLoop--) {
        solveit();
    }

}