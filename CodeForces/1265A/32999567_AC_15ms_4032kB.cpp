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

    int t,i,n;
    bool fo=true;
    string s,r;

    cin>>t;

    while(t--)
    {
        r="";
        fo=true;
        cin>>s;
        n=s.length();
        for(i=0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                if(s[i]==s[i+1] && i!=(n-1) )
                {
                    cout<<"-1\n";
                    fo=false;
                    break;
                }
                else
                {
                    r+=s[i];
                }
            }else
            {
                if(i==0)
                {
                    if(!isalpha(s[i+1]))
                        r+='a';
                    else
                    {
                        if(s[i+1]=='a' || s[i+1]=='b')
                            r+='c';
                        else
                            r+='a';
                    }
                }
                else if(i==(n-1))
                {
                    if(r[i-1]=='a' || r[i-1]=='b')
                        r+='c';
                    else
                        r+='a';
                }

                else
                {
                    if(!isalpha(s[i+1]))
                    {
                        if(r[i-1]=='a' || r[i-1]=='b')
                            r+='c';
                        else
                            r+='a';
                    }
                    else
                    {
                        if(r[i-1]=='a' && s[i+1]=='b' ||r[i-1]=='b' && s[i+1]=='a') r+='c';
                        else if(r[i-1]=='a' && s[i+1]=='c' ||r[i-1]=='c' && s[i+1]=='a') r+='b';
                        else if(r[i-1]=='b' && s[i+1]=='c' ||r[i-1]=='c' && s[i+1]=='b') r+='a';
                        else if(r[i-1]=='a'||r[i-1]=='b') r+='c';
                        else r+='a';
                    }

                }


            }


        }

        if(fo==true) cout<<r<<"\n";

    }

}
