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

    int n,m,a,b,i;

    cin>>n>>m;
    int arr[m+2]={0};

    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        arr[a]+=1;
        arr[b+1]-=1;
    }

    for(i=1;i<=m;i++)
    {
        arr[i]+=arr[i-1];
    }

    queue<int>q;
    for(i=1;i<=m;i++)
    {
        if(arr[i]==0)q.push(i);
    }

    cout<<q.size()<<"\n";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

}
