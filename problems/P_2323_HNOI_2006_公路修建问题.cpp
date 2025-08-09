#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MAXDSU = 1e5;

vector<int> dsu (MAXDSU,0);
vector<int> dsusize (MAXDSU,0);

void builddsu(int n){
    for(int i  = 1;i <= n;i++){
        dsu[i] = i;
        dsusize[i] = 1;
    }
}

int find(int x){
    queue<int> q;
    while(dsu[x] != x){
        q.push(x);
        x = dsu[x];
    }
    while(!q.empty()){
        dsu[q.front()] = x;
        q.pop();
    }
    return x;
}

void uni(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        dsu[fa] = fb;
        dsusize[fb] += dsusize[fa];
    }
}

const long long MOD = 1e9 + 7;

struct edge {
    int ind;
    int u,v;
    int cost;

    bool operator < (edge e2) const {
        return cost < e2.cost;
    }

};

void solve(){
    int n,k,m;
    cin >> n >> k >> m;
    builddsu(n);
    vector<int> ans (m + 5,-1);
    vector<edge> edge1;
    vector<edge> edge2;
    for(int i = 1;i < m;i++){
        int u,v,w1,w2;
        cin >> u >> v >> w1 >> w2;
        edge1.push_back({i,u,v,w1});
        edge2.push_back({i,u,v,w2});
    }
    sort(all(edge1));
    sort(all(edge2));
    int cnt = 0;
    int i = 0;
    int ans2 = -1;
    while(cnt < k){
        int u = edge1[i].u;
        int v = edge1[i].v;
        int cost = edge1[i].cost;
        if(find(u) != find(v)){
            uni(u,v);
            ans[edge1[i].ind] = 1;
            ans2 = max(cost,ans2);
            cnt++;
        }
        i++;
    }
    for(int j = 0;j < edge2.size();j++){
        int u = edge2[j].u;
        int v = edge2[j].v;
        int cost = edge2[j].cost;
        if(find(u) != find(v)){
            uni(u,v);
            ans[edge2[j].ind] = 2;
            ans2 = max(cost,ans2);
        }
    }
    cout << ans2 << "\n";
    for(int i = 1;i < m;i++){
        if(ans[i] == -1) continue;
        cout << i << " " << ans[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}