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

    int t,a,b;
    cin>>t;

    while (t--) {
        cin>>a>>b;

        cout<<min((a+b)/4,min(a,b))<<"\n";
    }


    return 0;
}