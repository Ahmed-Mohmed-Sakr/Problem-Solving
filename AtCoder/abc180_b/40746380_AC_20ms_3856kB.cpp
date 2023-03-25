#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//typedef unsigned long long ll;
#define int long long
///---------------- by:Ahmed Sakr (sakr_) with AZA ------------------///
//const int M=(int) 1e9+7;


void doIt() {

    int n,a; cin>>n;
    int ans1=0,ans2=0,ans3=-100;

    for(int i=0;i<n;i++) {
        cin>>a;
        if(a<0) a*=-1;

        ans1+=a;
        ans2+=(a*a);
        ans3=max(ans3,a);
    }

    cout<<ans1<<"\n";
    cout<<fixed<<setprecision(15)<<sqrt(ans2)<<"\n";
    cout<<ans3;

}

int32_t main() {

    FAST
    int t = 1; ///cin >> t;
    while (t--) {
        doIt();
    }
}
