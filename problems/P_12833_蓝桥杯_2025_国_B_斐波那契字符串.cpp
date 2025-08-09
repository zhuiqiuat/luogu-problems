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
struct status {
    ll z = 0;
    ll o = 0;
    ll ans = 0;
};
vector<status> ans;

void solve(){
    int x;
    cin >> x;
    cout << ans[x - 1].ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ans.push_back({1,0,0});
    ans.push_back({0,1,0});
    for(int i = 2;i <= 1e5;i++){
        ll z = ans[i - 2].z + ans[i - 1].z;
        z %= MOD;
        ll o = ans[i - 2].o + ans[i - 1].o;
        o %= MOD;
        ll ans2 = ans[i - 2].ans + ans[i - 1].ans;
        ans2 %= MOD;
        ans2 += ans[i - 2].o * ans[i - 1].z;
        ans2 %= MOD;
        ans.push_back({z,o,ans2});
    }
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}