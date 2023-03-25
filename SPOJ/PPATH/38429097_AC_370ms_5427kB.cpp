/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf INT_MAX

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)1e4+5;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int solve() {
    int a,b;
    string s1,s2,s;

    cin>>s1>>s2;
    stringstream xx; xx<<s1; xx>>a;
    stringstream yy; yy<<s2; yy>>b;


    int dis[N];
    memset(dis,-1,sizeof dis);
    dis[a]=0;

    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int u=q.front(); q.pop();

        char i,n=s2[0];
        stringstream x1;
        x1<<u;
        x1>>s;
        for(i='1';i<='9';i++) {
            s[0]=i;
            stringstream nums;
            int num;
            nums<<s;
            nums>>num;

            if(isPrime(num ) && dis[num]==-1) {
                q.push(num);
                dis[num] = dis[u]+1;
            }
        }

        n=s2[1];
        stringstream x2;
        x2<<u;
        x2>>s;
        for(i='0';i<='9';i++) {
            s[1]=i;
            stringstream nums;
            int num;
            nums<<s;
            nums>>num;

            if(isPrime(num ) && dis[num]==-1) {
                q.push(num);
                dis[num] = dis[u]+1;
            }
        }

        n=s2[2];
        stringstream x3;
        x3<<u;
        x3>>s;
        for(i='0';i<='9';i++) {
            s[2]=i;
            stringstream nums;
            int num;
            nums<<s;
            nums>>num;

            if(isPrime(num ) && dis[num]==-1) {
                q.push(num);
                dis[num] = dis[u]+1;
            }
        }

        n=s2[3];
        stringstream x4;
        x4<<u;
        x4>>s;
        for(i='0';i<='9';i++) {
            s[3]=i;
            stringstream nums;
            int num;
            nums<<s;
            nums>>num;

            if(isPrime(num ) && dis[num]==-1) {
                q.push(num);
                dis[num] = dis[u]+1;
            }
        }

    }


    return dis[b];
}

int main() {
    FAST

    int t; cin>>t;

    while (t--) {
        cout<<solve()<<"\n";
    }

}

