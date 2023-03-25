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

long long gcd(long long  a, long long  b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void doIt() {

    int a,b,c; cin>>a>>b>>c;

    ///lcm(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = 2520
    ///or
    ///10! = 3628800

    int ans = 1;
    for(int i=2;i<=10;i++){
        ans= lcm(ans,i);
    }
    
    cout<<power(a, power(b,c,ans),10);
    ///cout<<power(a, power(b,c,3628800),10);


}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
