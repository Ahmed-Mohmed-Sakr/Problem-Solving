#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define int long long
int dp[61][61];

int count (string & s, int idx1, int idx2) {
    if(idx1 > idx2) return 0;
    if(idx1 == idx2) return 1;
    if(idx2 - idx1 == 1) return 2 + (s[idx2] == s[idx1]);

    auto & ret = dp[idx1][idx2];
    if(~ret) return ret;
//=====================================================================
    int ans = 0;
    if(s[idx1] == s[idx2]) ans += 1 + count(s, idx1 + 1, idx2 - 1);
    ans += count(s, idx1 + 1, idx2);
    ans += count(s, idx1, idx2 - 1);
    ans -= count(s, idx1 + 1, idx2 - 1);
//=====================================================================
    return ret = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    string s; cin >> s;
    cout << count(s, 0, (int)s.size() - 1) << endl;
}
int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while(t--) solve();
}
