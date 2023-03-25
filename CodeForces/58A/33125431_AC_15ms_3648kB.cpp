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

    int n,c=0,i;
    char w[]="hello";
    string s;

    cin>>s;
    n=s.length();

    for(i=0;i<n;i++)
    {
        if(s[i]==w[c])
        {
            c++;
            if(c==5)
            {
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";

}
