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

    int t,n,a,even=0,odd=0,i;

    cin>>t;

    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0)even++;
            else odd++;
        }
        if(odd>0) cout<<even<<"\n";
        else cout<<"-1\n";

        even=0;
        odd=0;
    }
}
