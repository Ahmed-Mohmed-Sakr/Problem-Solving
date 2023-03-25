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

    int n,a,mi,ma,ans=0;

    cin>>n>>a;
    n--;
    mi=ma=a;

    while(n--)
    {
        cin>>a;

        if(a<mi)
        {
            ans++;
            mi=a;
        }
        else if(a>ma)
        {
            ans++;
            ma=a;
        }
    }

    cout<<ans;


    return 0;
}
