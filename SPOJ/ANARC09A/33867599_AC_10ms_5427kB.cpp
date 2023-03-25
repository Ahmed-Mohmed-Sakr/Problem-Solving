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
    int i,l,ans=0,c=1;

    while (cin>>s){
        if(s[0]=='-') break;
        l=s.length();
        stack<char>st;

        for(i=0 ;i<l;i++)
        {
            if(st.empty())
            {
                if(s[i]=='{') st.push('{');
                else
                {
                    ans++;
                    st.push('{');
                }
            }
            else
            {
                if(s[i]=='{')
                {
                    st.push('{');
                }
                else
                {
                    st.pop();
                }

            }

        }
        cout<<c<<". "<<ans+(st.size()/2)<<"\n";
        ans=0;
        c++;
    }


}
