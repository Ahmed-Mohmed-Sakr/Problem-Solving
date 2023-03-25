#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//typedef unsigned long long ll;
#define int unsigned long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
//const int M=(int) 1e9+7;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}


void doIt() {

    int a,b,c; cin>>a>>b>>c;

    ///lcm(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = 2520
    cout<<power(a, power(b,c,2520),10);

}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
