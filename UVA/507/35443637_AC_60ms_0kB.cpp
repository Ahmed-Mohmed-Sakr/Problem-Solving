#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
#define pi 3.14159265
using namespace std;
/*
by:Ahmed Sakr (sakr_) with AZA ;
#ifndef ONLINE_JUDGE
   freopen("c.in", "r", stdin);
#endif
  __builtin_popcountll();
*/
bool isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0) return false;
    return true;
}

int main() {
    Sakr_

    int b,a,n,sum,msum,begin,end,l,x,i;
    int c=1;
    scanf("%d", &b);

    while (b--) {
        scanf("%d", &a);

        begin=end = 0;
        sum=msum=0;
        x=1;
        l=0;
        for(i=1;i<a;i++) {
            scanf("%d", &n);
            sum+=n;
            if(sum<0) {
                x=i+1;
                sum=0;
            } else if(msum < sum || (sum==msum && (i-x)>l)) {
                msum = sum;
                begin = x;
                end = i;
                l = i-x;
            }

        }

        if(msum) {
            printf("The nicest part of route %d is between stops %d and %d\n", c, begin, end+1);
        } else {
            printf("Route %d has no nice parts\n", c);
        }
        c++;

    }

}