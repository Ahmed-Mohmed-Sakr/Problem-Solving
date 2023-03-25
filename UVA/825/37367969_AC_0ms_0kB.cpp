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

int r,c;
vector<vector<bool>> arr;
vector<vector<int>> dp;

int solve (int a,int b) {

    if(a>=r || b>=c) {
        return 0;
    }

    if(arr[a][b] == 1) return 0;

    if(a == r-1 && b==c-1) {
        return 1;
    }

    int &ans= dp[a][b];
    if(ans!=-1) return ans;

    ans= solve(a,b+1);
    ans+= solve(a+1,b);

    return ans;

}


void solveit(int t) {

    cin>>r>>c;

    cin.ignore();
    arr = vector<vector<bool>>(r+2,vector<bool>(c+2,0));
    dp = vector<vector<int>>(r+2,vector<int>(c+2,-1));

    int row,col;
    string s;
    for(int i=0;i<r;i++) {
        getline(cin,s);
        stringstream temp(s);
        temp >> row;
        row--;

        while (temp>>col) {
            arr[row][col-1]=1;
        }

    }

    cout<<solve(0,0)<<"\n";
    if(t) cout<<"\n";

}

int32_t main() {
    ///Sakr_

    //////////freopen("garden.in","r",stdin);
    int timeOfRepeteLoop = 1;
    cin>>timeOfRepeteLoop;
    while (timeOfRepeteLoop--) {
        solveit(timeOfRepeteLoop);
    }



}


