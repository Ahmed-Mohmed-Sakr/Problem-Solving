#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define ll long long int
using namespace std;

int main()
{Sakr_;

    int n,m,i,j;
    char c;

    cin>>n>>m>>c;
    char arr[n+2][m+2];

    for(i= 0;i<n+2;i++) {
        for(j=0;j<m+2;j++) {
            arr[i][j]='.';
        }
    }

    for(i= 1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            cin>>arr[i][j];
        }
    }

    set<char> ans;

    ans.insert('.');
    ans.insert(c);
    for(i= 1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(arr[i][j]==c) {
               ans.insert(arr[i][j-1]);
               ans.insert(arr[i][j+1]);
               ans.insert(arr[i-1][j]);
               ans.insert(arr[i+1][j]);
            }
        }
    }

    cout<<ans.size() -2;
}