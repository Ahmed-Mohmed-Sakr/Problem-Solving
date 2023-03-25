#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
//const int M=(int) 1e9+7;


void doIt() {

    int n;
    cin >> n;

    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(),ans.end());

    for(auto xx: ans) {
        cout<<xx<<"\n";
    }

}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
