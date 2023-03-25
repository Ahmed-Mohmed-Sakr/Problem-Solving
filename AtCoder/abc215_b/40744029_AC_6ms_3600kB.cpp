#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
const int M=(int) 1e9+7;


void doIt() {

    int n; cin>>n;

    int c=0;
    int ans=2;
    while (ans<=n) {
        c++;
        ans*=2;
    }
    cout<<c;

}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
