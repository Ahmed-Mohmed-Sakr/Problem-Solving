#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define ll long long int
using namespace std;

/*
by:Ahmed Sakr (sakr_) with AZA ;l

#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif
*/


int main()
{Sakr_;

    int n,k,y,c=0;

    cin>>n>>k;

    while(n--)
    {
        cin>>y;

        if(y+k<=5)c++;
    }

    cout<<c/3;



    return 0;
}
