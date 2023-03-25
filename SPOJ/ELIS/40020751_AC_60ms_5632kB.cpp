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

const int N= (int)10+9;
const int M= (int)1e9+7;

int arr[N];
int n;
int dp[N][N];
int solve(int i,int prev) {

    if(i>n) return 0;

    int &ans = dp[i][prev];
    if(~ans) return ans;

    ans=0;
    ans = max(ans, solve(i+1,prev));

    if(arr[prev]<arr[i]) {
        ans = max(ans, 1+solve(i+1,i));
    }

    return ans;
}

void doIt() {

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    arr[0]=-1;
    memset(dp,-1,sizeof dp);
    cout<< solve(0,0);

}

int32_t main() {
    FAST

    int t = 1;
    ///cin >> t;
    while (t--) {
        doIt();
    }
}