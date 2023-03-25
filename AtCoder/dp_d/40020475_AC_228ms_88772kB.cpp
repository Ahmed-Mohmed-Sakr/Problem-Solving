/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

const int N= (int)1e2+9;
const int M= (int)1e9+7;

int w[N],v[N];
int n,wi;
int dp[N][(int)1e5+5];
int solve(int i,int rem) {

    if (i >= n) return 0;

    int &ans = dp[i][rem];
    if (~ans) return ans;

    ans = 0;
    ans = max(ans, solve(i + 1, rem));

    if (rem >= w[i])
        ans = max(ans, v[i] + solve(i + 1, rem - w[i]));

    return ans;

}

void doIt() {

    cin>>n>>wi;

    for(int i=0;i<n;i++) {
        cin>>w[i]>>v[i];
    }
    memset(dp,-1,sizeof dp);
    cout<< solve(0,wi);

}

int32_t main() {
    FAST

    int t = 1;
    ///cin >> t;
    while (t--) {
        doIt();
    }
}