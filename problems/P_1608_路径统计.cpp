#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll fastpow(ll a,ll b,ll mod){
    ll ans = 1;
    if(mod != 0){
        a %= mod;
    }
    while(b > 0){
        if(b & 1){
            ans *= a;
            if(mod != 0){
                ans %= mod;
            }
        }
        a *= a;
        if(mod != 0){
            a %= mod;
        }
        b >>= 1;
    }
    return ans;
}

bool isprime(ll n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5;i * i <= n;i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

const int MAXDSU = 1e5 + 50;

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

struct cmp {
    bool operator() (vector<int> v1,vector<int> v2){
        return v1[1] > v2[1];
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph (n + 5);
    set<vector<int>> v2;
    for(int i = 0;i < m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(v2.find({u,v,w}) != v2.end()) continue;
        v2.insert({u,v,w});
        graph[u].push_back({v,w});
    }
    vector<int> dis (n + 5,INT_MAX);
    vector<int> cnt (n + 5,0);
    vector<bool> vist (n + 5,0);
    dis[1] = 0;
    cnt[1] = 1;
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    pq.push({1,0});
    while(pq.size()){
        int now = pq.top()[0];
        pq.pop();
        if(vist[now]) continue;
        vist[now] = true;
        for(auto& [to,cost] : graph[now]){
            if(dis[to] > dis[now] + cost){
                dis[to] = dis[now] + cost;
                cnt[to] = cnt[now];
                pq.push({to,dis[to]});
            }else if(dis[to] == dis[now] + cost){
                cnt[to] += cnt[now];
            }
        }
    }
    if(dis[n] != INT_MAX) cout << dis[n] << " " << cnt[n];
    else cout << "No answer";
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