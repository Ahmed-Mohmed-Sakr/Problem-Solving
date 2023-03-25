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

    int n,i,c=0;
    string s;

    cin>>n>>s;

    for(i=1;i<n;i++)
    {
        if(s[i]==s[i-1]) c++;
    }

    cout<<c;

}
