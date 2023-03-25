#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
//const int M=(int) 1e9+7;


void doIt() {

    int n, m, a;
    cin >> n >> m;

    bool isfactorial[(int) 1e5 + 5] = {false};

    for (int i = 0; i < n; i++) {
        cin >> a;

        for (int j = 2; j * j <= a; j++) {

            while (a % j == 0) {
                isfactorial[j] = true;
                a /= j;
            }
        }
        if (a > 1) isfactorial[a] = true;

    }

    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        a = i;
        bool can = false;
        for (int j = 2; j * j <= a; j++) {

            while (a % j == 0) {
                can |= isfactorial[j];
                a /= j;
            }
        }
        if (a > 1) can |= isfactorial[a];

        if (!can) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (auto xx: ans)cout << xx << "\n";


}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
