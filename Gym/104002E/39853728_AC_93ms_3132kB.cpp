/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

bool isPrime(int n) {
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

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

const int N= (int)2e5+9;
const int M= (int)1e9+7;


bool valid(int a,int b) {
    //return (a >= 0 && a < n && b >= 0 && b < m);
}

void solve() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i += 2) {

        if (pq.empty()) {
            pq.push(min(-arr[i], -arr[i + 1]));
            sum += max(arr[i], arr[i + 1]);
        } else {
            int ma = max(arr[i], arr[i + 1]);
            if (sum + ma < (sum + pq.top() + arr[i] + arr[i + 1])) {
                sum += pq.top() + arr[i] + arr[i + 1];
                pq.pop();
                pq.push(-arr[i]);
                pq.push(-arr[i + 1]);
            } else {
                pq.push(min(-arr[i], -arr[i + 1]));
                sum += max(arr[i], arr[i + 1]);
            }
        }
    }

    ////cout<<pq.size()<<"\n";
    cout << sum;


}

int32_t main() {
    FAST
    int t=1;
    while (t--) {
        solve();
    }
}