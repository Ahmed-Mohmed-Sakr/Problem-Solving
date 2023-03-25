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

    int t,k,p=0,a=0,ans=0,i;
    string s;

    cin>>t;
    while(t--)
    {
        cin>>k>>s;
        for(i=0;i<k;i++)
        {
            if(s[i]=='A')
            {
                if(a>0)
                {
                    ans=max(ans,p);
                }
                p=0;
                a++;
            }
            else
            {
                p++;
            }
        }

        if(a>0)
        {
            ans=max(ans,p);
        }

        cout<<ans<<"\n";

        p=0;
        a=0;
        ans=0;


    }

    return 0;
}
