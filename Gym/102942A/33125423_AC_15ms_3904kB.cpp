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

    int t,n,i,d=0;
    char w[]="ENWS";
    string s;

    cin>>t;
    while(t--)
    {
        d=0;
        cin>>n>>s;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                d=(d+1)%4;
            }
            else
            {

                d=((d-1)%4 +4)%4;
            }
        }

        cout<<w[d]<<"\n";
    }
}
