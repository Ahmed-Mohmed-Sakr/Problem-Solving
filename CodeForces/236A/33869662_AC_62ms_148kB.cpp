#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define ll long long int
using namespace std;

/*
by:Ahmed Sakr (sakr_) with AZA ;l

#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif

  __builtin_popcount(x);

*/


int main()
{Sakr_;

    string s;
    int i,n;

    cin>>s;
    set<char>st;
    n=s.length();

    for(i=0;i<n;i++)
    {
        st.insert(s[i]);
    }

    if((st.size())%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";


}
