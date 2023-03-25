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

    int i,j,a;


    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            cin>>a;
            if(a==1)
            {
                cout<<abs(i-3)+abs(j-3);
                return 0;
            }
        }
    }

}
