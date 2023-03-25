/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)2e2+5;



int main() {
    FAST

    int k;
    cin>>k;
    k--;
    vector<int> arr;
    int n;
    
    while(cin>>n) {
        arr.push_back(n);
    }

    sort(arr.rbegin(),arr.rend());
    
    cout<<arr[k];


}

