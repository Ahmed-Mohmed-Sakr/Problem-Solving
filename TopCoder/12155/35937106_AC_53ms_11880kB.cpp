#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define int  long long
using namespace std;
/**
 * by:Ahmed Sakr (sakr_) with AZA ;
 * freopen("input.txt","r",stdin);
 * freopen("output.txt","w",stdout);
 * __builtin_popcountll();
**/



class CuttingBitString {

public:
    string s;
    int n;
    map<string,bool> isPowerOfFive;
    int dp[55];

    int getmin(string ss){

        s = ss;

        int f=1;
        for(int i=0;i<33;i++) {

            int temp=f;
            string sFive="";
            while (temp>0) {

                if(temp&1) {
                    sFive="1"+sFive;
                } else {
                    sFive="0"+sFive;
                }
                temp = (temp>>1);
            }

            isPowerOfFive[sFive]= true;
            f*=5;
        }

        n= s.length();
        memset(dp,-1,sizeof dp);

        int ans = solve(0);
        if(ans == (int)1e14) return -1;
        else return ans;
    }

    int solve(int i) {
        if(i==n) {
            return 0;
        }

        int &ans=dp[i];
        if(ans!=-1)return ans;

        ans = 1e14;
        string xx="";
        for(int j=i;j<n;j++) {
            xx+=s[j];
            if(isPowerOfFive[xx])
                ans=min(ans, 1+solve(j+1));
        }

        return ans;

    }
};
