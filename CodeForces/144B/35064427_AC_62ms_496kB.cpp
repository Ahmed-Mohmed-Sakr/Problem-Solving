#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define ll long long int
using namespace std;

/*
by:Ahmed Sakr (sakr_) with AZA ;

#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif

  __builtin_popcount(x);

*/

int arr[103];
int main() {
    //Sakr_;

    int a,b,c,d,x1,x2,y1,y2,i,j,n;

    cin>>a>>b>>c>>d;

    x1=min(a,c);
    x2=max(a,c);
    y1=min(b,d);
    y2=max(b,d);
    multimap<double,double> points;

    for(i=x1;i<=x2;i++) {
        if(!(i==x1 || i==x2)) {
            points.insert({i,y1});
            points.insert({i,y2});
        } else {

            for(j=y1;j<=y2;j++) {
                points.insert({i,j});
            }
        }

    }

    cin>>n;
    int x[n],y[n],r[n],count=0;
    double ans;

    for(i=0;i<n;i++) {
        cin>>x[i]>>y[i]>>r[i];
    }

    bool worm = false;
    auto it = points.begin();
    for(;it!=points.end();it++) {
        worm = false;
        for(i=0;i<n;i++) {
            ans = sqrt(pow((x[i] - it->first), 2) + pow((y[i] - it->second), 2));
            //cout << ans<<"\n";

            if (ans <= r[i]) {
                //cout<<it->first<<" "<<it->second<<" "<<x[i]<<" "<<y[i]<<" "<<r[i]<<" "<<ans<<"\n";
                worm= true;
                break;
            }
        }
        if(worm== false) count++;
    }

    cout<<count;

}