/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

const int N= (int)1e4+9;
const int M= (int)1e9+7;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool valid(int a,int b) {
    //return (a >= 0 && a < n && b >= 0 && b < m);
}


void solve() {

    ll n,a; cin>>n;

    ll ans=0;
    for(int i=0;i<n;i++) {
        cin>>a;
        ans+=(a-1);
    }

    cout<<ans;

}

int main() {
    FAST

   int t=1;
    while (t--) {
        solve();
    }
}

