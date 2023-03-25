#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;
#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif
  __builtin_popcount();
*/

int main() {
    Sakr_

    ll a,b,od;

    cin>>a>>b;

    od=(a/2) +(a%2);

    if(b<=od) {
        cout<<(2*b)-1;
    } else {
        b-=od;
        cout<<(2*b);
    }


    return 0;
}