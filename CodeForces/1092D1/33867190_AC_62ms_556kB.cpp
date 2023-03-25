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

    int n,a,t;
    stack<int>st;

    cin>>n;
    while (n--) {
        cin>>a;
        if(st.empty())
        {
            st.push(a);
        }
        else
        {
            t=abs(a-st.top());
            if(t%2== 0)
            {
                st.pop();
            }
            else
            {
                st.push(a);
            }
        }
    }

    if(st.size() <=1) cout<<"YES";
    else cout<<"NO";

}
