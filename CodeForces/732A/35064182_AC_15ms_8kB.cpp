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

    int k,r,t;

    cin>>k>>r;

    int ans=1;
    t=k;
    while (!(t%10==r || t%10 ==0)) {
        ans++;
        t+=k;
    }

    cout<<ans;

    return 0;
}