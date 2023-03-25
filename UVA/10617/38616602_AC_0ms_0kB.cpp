#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define int long long
int dp[65][65];
string s;

int count (int idx1, int idx2) {
    if(idx1 > idx2) return 0;
    if(idx1 == idx2) return 1;
    if(idx2 - idx1 == 1) return 2 + (s[idx2] == s[idx1]);

    auto & ans = dp[idx1][idx2];
    if(~ans) return ans;
//=====================================================================
    ans = 0;
    if(s[idx1] == s[idx2]) ans += 1 + count(idx1 + 1, idx2 - 1);
    ans += count(idx1 + 1, idx2);
    ans += count(idx1, idx2 - 1);
    ans -= count(idx1 + 1, idx2 - 1);
//=====================================================================
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << count(0, (int)s.size() - 1) << endl;
}
int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while(t--) solve();
}
