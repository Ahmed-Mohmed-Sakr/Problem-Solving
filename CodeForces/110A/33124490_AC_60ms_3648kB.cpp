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

    ll n,x,c=0;
    cin>>n;

    while(n>0)
    {
        x=n%10;

        if(x== 7 || x== 4)
        {
            c++;
        }
        n/=10;
    }

    if(c==4 || c==7) cout<<"YES";
    else cout<<"NO";

}
