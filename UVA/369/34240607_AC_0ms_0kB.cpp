#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define ll long long int
using namespace std;

int main()
{//Sakr_;

    double n,m,ans=1,y;
    int x=n-m;

    while(cin>>n>>m) {
        int x=n-m;
        y=n;
        for(;x>=1;x--) {
        ans*=(y/x);
        y--;
        }
        
        if(n!=0 && m!=0)
        cout<<n<<" things taken "<<m<<" at a time is "<<(ll)round(ans)<<" exactly.\n";

        ans=1;
    }
}
