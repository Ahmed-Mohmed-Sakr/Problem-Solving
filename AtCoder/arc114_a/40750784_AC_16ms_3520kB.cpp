#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
//const int M=(int) 1e9+7;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


void doIt() {

    int n,a;
    cin >> n;

   int ans=(int)1e18;

   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];


   vector<int> p;
   for(int i=2;i<50;i++) {
       if(isPrime(i))p.push_back(i);
   }


   int len =p.size();
   for(int i=0;i<(1ll<<len);i++) {
       int subans=1;
       for(int j=0;j<len;j++) {
           if((i&(1ll << j))) subans*=p[j];
       }

       bool can = true;
       for(int j=0;j<n;j++) {
           if(__gcd(subans,arr[j]) == 1) {
               can= false;
               break;
           }
       }

       if(can) ans=min(ans,subans);
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
