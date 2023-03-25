#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
////typedef long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
////const int M=(int) 1e9+7;

int n;
vector<int> arr;

int solve(int i,int prev) {
    /// base case
    if(i>n)
        return 0;

    int ans = -10;

    if(arr[prev] < arr[i]){
        ans = max(ans, 1+solve(i+1,i));
    }

    ans = max(ans,solve(i+1,prev));

    return ans;

}

void doIt() {


    cin>>n;
    arr = vector<int>(n+5);
    for(int i=1 ;i<=n;i++) {
        cin>>arr[i];
    }
    arr[0] =-10;

    cout<<solve(0,0);



}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}