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

    int t,i,n,odd=0;
    string s;

    cin>>t;

    while(t--)
    {
        odd=0;
        cin>>n>>s;

        for(i=0;i<n;i++)
        {
            if(((s[i]-'0'))%2 !=0) odd++;
        }

        int c=2;

        if(odd<=1)
        {
            cout<<-1<<"\n";
        }
        else
        {
            for(i=0;i<n;i++)
            {
               if(((s[i]-'0'))%2 !=0)
                {
                    cout<<s[i];
                    c--;
                    if(c==0)break;
                }
            }
            cout<<"\n";
        }

    }

}
