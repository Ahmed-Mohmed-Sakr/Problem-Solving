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

    ll n,t=0,k=0,i,c=0;

    cin>>n;

    int arr[n];

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        t+=arr[i];
    }
    sort(arr,arr+n);
    t=t/2;

    for(i=n-1;i>=0;i--)
    {
        k+=arr[i];
        c++;
        if(k>t)break;
    }

    cout<<c;

}
