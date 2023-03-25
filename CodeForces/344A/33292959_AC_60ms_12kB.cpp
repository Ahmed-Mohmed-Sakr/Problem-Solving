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

    int n,c=1;
    string s1,s2;
    cin>>n>>s1;
    n--;
    while(n--)
    {
        cin>>s2;

        if(s1[1]==s2[0])c++;

        s1=s2;

    }

    cout<<c;

}
