#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
////typedef long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
////const int M=(int) 1e9+7;

int n, total;
vector<int> arr;

// p1 => sum
// p2 => total-sum;
int dp[105][50010];
int solve(int i,int sum) {

    if(i==n) {
        return abs(sum - (total-sum));
    }
    
    int &ans = dp[i][sum];
    if(ans!=-1) return ans;
    
    ans = (int)1e9;
    ans = min(ans,solve(i+1,sum+arr[i]));
    ans = min(ans,solve(i+1,sum));

    return ans;
}



void doIt() {


    cin>>n;
    total = 0;
    arr = vector<int>(n+5);
    for(int i=0 ;i<n;i++) {
        cin >> arr[i];
        total+=arr[i];
    }
    memset(dp,-1,sizeof dp);
    
    cout<<solve(0,0)<<"\n";


}

int32_t main() {

    FAST
    int t = 1; cin >> t;
    while (t--) {
        doIt();
    }
}