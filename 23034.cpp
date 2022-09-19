#include <bits/stdc++.h>
using namespace std;
const int IDX = 1001;
typedef pair<int,int> pii;
int parent[IDX];
priority_queue<pair<int,pii>> pq;
vector<pii> v[IDX];
int a[IDX][IDX];
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    parent[x] = y;
}
int dfs(int root, int now,int end){
    if(now == end){
        return a[root][now];
    }
    int ret = 0;
    int size = v[now].size();
    for(int i=0;i<size;i++){
        int cost = 0;
        int next = v[now][i].first;
        if(next == root) continue;
        cost = max(cost,dfs(now,next,end));
        if(cost!=0){
            ret= max(cost,a[now][next]);
        }
    }
    return ret;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); 
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s,e,cost;
        cin>>s>>e>>cost;
        pq.push({-cost,{s,e}});
        a[s][e] = cost;
        a[e][s] = cost;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) parent[i] = i;
    while(!pq.empty()){
        auto _auto = pq.top();
        pq.pop();
        int cost = -_auto.first;
        int s = _auto.second.first;
        int e = _auto.second.second;
        if(find(s) == find(e)) continue;
        ans+=cost;
        v[s].push_back({e,cost});
        v[e].push_back({s,cost});
        Union(s,e);
    }
    int t;
    cin>>t;
    while(t--){
        int s,e;
        cin>>s>>e;
        cout<<ans-dfs(s,s,e)<<'\n';
    }
    
    return 0;
}
