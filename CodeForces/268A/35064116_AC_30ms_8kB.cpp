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

    int n;
    cin>>n;

    int a1[n] ,a2[n];
    for(int i=0;i<n;i++) {
        cin>>a1[i]>>a2[i];
    }

    int ans=0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(a1[i] == a2[j]) ans++;
            if(a2[i] ==a1[j]) ans++;
        }
    }

    cout<<ans;



    return 0;
}