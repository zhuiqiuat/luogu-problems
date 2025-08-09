#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll fastpow(ll a,ll b,ll mod);
bool isprime(ll n);

ll mod = 80112002;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 5,vector<int> ());
    int cnt[n + 5] = {0};
    ll dp[n + 5] = {0};
    for(int i = 1;i <= m;i++){
        int v,w;
        cin >> v >> w;
        cnt[w]++;
        graph[v].push_back(w);
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(cnt[i] == 0){
            q.push(i);
            dp[i] = 1;
        }
    }
    ll ans = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(graph[now].empty()){
            ans += dp[now];
            ans %= mod;
        }else{
            for(auto& i : graph[now]){
                cnt[i]--;
                if(cnt[i] == 0) q.push(i);
                dp[i] += dp[now];
                dp[i] %= mod;
            }
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