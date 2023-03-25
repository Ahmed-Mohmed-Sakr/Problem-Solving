#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
//const int M=(int) 1e9+7;


void doIt() {

    int n;
    cin >> n;

   int ans=0;

   for(int i=1;i<=n;i++) {
       for(int j=1;j<=n;j++) {
           if(i*j>n) {
               break;
           }
           for(int z=1;z<=n;z++) {
               if(i*j*z>n){
                   break;
               }
               ans++;
           }
       }
   }

   cout<<ans<<"\n";

}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
