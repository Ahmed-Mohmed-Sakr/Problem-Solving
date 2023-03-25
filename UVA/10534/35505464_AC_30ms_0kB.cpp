#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
#define pi 3.14159265
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;
#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif
  __builtin_popcountll();
*/
bool isPrime(int x) {
    if (x <= 1) return false;   if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6) if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

int binarysearsch(vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}


int n;

vector<int>arr;

vector<int> lis()
{

    vector<int> liss(n, 0);
    vector<int> dp(n,1);
    int l = 1,pos;

    liss[0] = arr[0];
    for (int i = 1; i < n; i++) {

        if (arr[i] > liss[l - 1]) {
            liss[l] = arr[i];
            l++;
            dp[i] = l;
        }
        else {
            pos = binarysearsch(liss, -1, l - 1, arr[i]);
            liss[pos] = arr[i];
            dp[i] = pos+1;
        }
    }
    return dp;
}


void solveit() {

    while (cin>>n) {
        arr = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> a = lis();

        reverse(arr.begin(), arr.end());
        vector<int> b = lis();

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, 2 * min(a[i], b[n-1-i])-1);
        }
        cout << ans << "\n";
    }
}

int main() {
    Sakr_

    int t = 1;
    ///cin>>t;
    while (t--) {
        solveit();
    }

}