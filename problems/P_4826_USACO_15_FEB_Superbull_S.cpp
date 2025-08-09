#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

int dsu[2050] = {0};
int cnt = 0;

void build(int n){
    cnt = n;
    for(int i = 0;i < n;i++){
        dsu[i] = i;
    }
}

int find(int x){
    queue<int> q;
    while(dsu[x] != x){
        q.push(x);
        x = dsu[x];
    }
    while(q.size()){
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
        cnt--;
    }
}

struct edge {
    int u,v;
    int x;
};

bool cmp(edge e1,edge e2){
    return e1.x > e2.x;
}

void solve(){
    int n;
    cin >> n;
    build(n);
    vector<int> a (n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<edge> edges;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            edges.push_back({i,j,a[i] ^ a[j]});
        }
    }
    sort(all(edges),cmp);
    long long ans = 0;
    for(int i = 0;cnt != 1;i++){
        if(find(edges[i].u) != find(edges[i].v)){
            uni(edges[i].u,edges[i].v);
            ans += edges[i].x;
        }
    }
    cout << ans;
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