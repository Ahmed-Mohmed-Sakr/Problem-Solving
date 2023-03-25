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

    int n,i;

    while(cin>>n)
    {
        if(n==0)break;
        deque<int>q;
        for(i=1;i<=n;i++)q.push_back(i);

        if(q.size()==1)cout<<"Discarded cards:";
        else
        cout<<"Discarded cards: ";
        if(q.size()>=2)
        {
            cout<<q.front();
            q.erase(q.begin());
            q.push_back(q.front());
            q.erase(q.begin());
        }


        while(q.size()>1)
        {
            cout<<", "<<q.front();
            q.erase(q.begin());
            q.push_back(q.front());
            q.erase(q.begin());
        }

        cout<<"\nRemaining card: "<<q.front()<<"\n";
    }

}
