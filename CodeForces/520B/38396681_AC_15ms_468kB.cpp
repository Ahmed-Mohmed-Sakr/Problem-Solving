/// by:Ahmed Sakr (sakr_) with AZA ///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int N= (int)1e5+5;

int a,b;
int dis[N];

int bfs(int start) {
    if(a==b)return 0;
    queue<int>q;
    q.push(start);
    dis[start]=0;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        int res1 = s*2;
        int res2=s-1;


        if(res1>0 && dis[res1]==-1) {
            q.push(res1);
            dis[res1]=dis[s]+1;
        }

        if(res2>0 && dis[res2]==-1) {
            q.push(res2);
            dis[res2]=dis[s]+1;
        }
        int ans=(int)1e9;
        if(res1 == b) ans = dis[res1];

        if(res2 == b) ans= min(ans,dis[res2]);

        if(res1==b || res2==b) return ans;

    }

}

int main() {
    FAST
    cin>> a>>b;

    memset(dis,-1,sizeof dis);
    cout<<bfs(a);

}
