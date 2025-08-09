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

const long long MOD = 100003;

struct cmp {
    bool operator() (pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    int cnt[n + 5] = {0};
    vector<vector<pair<int,int>>> graph (n + 5);
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back({v,1});
        graph[v].push_back({u,1});
        // if(u == v) cnt[u]++;
    }
    int dji[n + 5];
    memset(dji,0x3f,sizeof(dji));
    bool vist[n + 5] = {0};
    dji[1] = 0;
    cnt[1] += 1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({1,0});
    while(pq.size()){
        int now = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if(vist[now]) continue;
        vist[now] = true;
        for(auto& p : graph[now]){
            int to = p.first;
            int dis = p.second;
            if(vist[to]) continue;
            if(dji[to] > dji[now] + dis){
                dji[to] = dji[now] + dis;
                cnt[to] = cnt[now] % MOD;
                pq.push({to,dji[to]});
            }else if(dji[to] == dji[now] + dis){
                cnt[to] += cnt[now];
                cnt[to] %= MOD;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << cnt[i] << "\n";
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