#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
#define pi 3.14159265
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  __builtin_popcountll();
*/


int maxContinSubArr(vector<int> &v) {

    int x=v.size();
    int ma = v[0];
    int dpv = v[0];

    for(int i=1;i<x;i++) {
        dpv = max(dpv+v[i],v[i]);
        ma = max(ma,dpv);
    }

    return ma;
}

int n;
vector<vector<int>> arr;
vector<int>sol ;

void solveit() {

    int i,j;
    while (cin>>n) {
        arr = vector<vector<int>>(n, vector<int>(n, 0));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int ans = arr[0][0];
        for (int i = 0; i < n; i++) {
            sol = vector<int>(n, 0);
            for (j = i; j < n; j++) {
                for (int x = 0; x < n; x++) {
                    sol[x] += arr[x][j];
                    ///cout<<sol[x]<<"  ";
                }
                ////cout<<"\n";
                int w = maxContinSubArr(sol);
                ans = max(ans, w);
            }
        }

        cout << ans<<"\n";
    }
}

int main() {
    //Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }

}