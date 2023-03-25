#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
const int M=(int) 1e9+7;


void doIt() {

    string s; cin>>s;
    int k; cin>>k;

    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout<<ans[k-1];
}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
