#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define int  long long
#define oo 1e15
using namespace std;
/**
 * by:Ahmed Sakr (sakr_) with AZA ;
 * freopen("input.txt","r",stdin);
 * freopen("output.txt","w",stdout);
 * __builtin_popcountll();
**/
class utility {

public :
    static int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
    static int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
};

struct st {
    int iq;
    int w;
    int id;
}arr[1001];

int w,iq;
int n;

bool comp(st &a,st &b) {
    if (a.w != b.w) {
        return a.w < b.w;
    }
    return a.iq > b.iq;
}

int dp[1001];

int solve(int i) {

    if(i==n) return 0;

    int &ans = dp[i];
    if(ans!=-1) return ans;

    ans = 1;

    for(int j=i+1;j<n;j++) {
        if (arr[i].w < arr[j].w && arr[i].iq > arr[j].iq) {
            ans = max(ans,1+ solve(j));
        }
    }

    return ans;
}


void solveit() {

    n=1;
    while (cin>>w>>iq) {
        ///if(w==-1)break;

        arr[n-1]={iq,w,n};
        n++;
    }
    n--;
    sort(arr,arr+n, comp);
    /*
    for(int i=0;i<n;i++) {
        cout<<arr[i].w<<"     "<<arr[i].iq<<"     "<<arr[i].id<<"\n";
    }
     */

    memset(dp,-1,sizeof dp);

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, solve(i));
        //cout<<ans<<"\n";
    }

    cout<<ans<<"\n";

    int t=ans;

    int prev;
    for(int i=0;i<n;i++) {
        if(t==dp[i] && t==ans) {
            prev = i;
            cout<<arr[i].id<<"\n";
            t--;
        } else if(t<ans && t==dp[i] &&(arr[i].w > arr[prev].w && arr[i].iq < arr[prev].iq)) {
            cout<<arr[i].id<<"\n";
            prev=i;
            t--;
        }

        if(t==0) break;
    }



}

int32_t main() {
    Sakr_

    int timeOfRepeteLoop = 1;
    /////cin>>timeOfRepeteLoop;
    while (timeOfRepeteLoop--) {
        solveit();
    }

}