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

const long long MOD = 1e9 + 7;
const long long MAX = 1e12;

vector<ll> fib;
vector<ll> suf;

ll now = 0;
int cnt = 0;

bool vist[150] = {0};
// int cnt2[60] = {0};

void dfs(ll now,int start){
    if(now == 0){
        cnt++;
        return;
    }else if(now < 0){
        return;
    }
    for(int i = start;i < fib.size();i++){
        if(vist[i]) continue;
        if(suf[i] < now) return;
        vist[i] = true;
        dfs(now - fib[i],i + 1);
        vist[i] = false;
    }
}

void solve(){
    ll n;
    cin >> n;
    dfs(n,0);
    cout << cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fib.push_back(1);
    fib.push_back(1);
    suf.push_back(1);
    suf.push_back(2);
    for(int i = 2;;i++){
        ll now = fib[i - 1] + fib[i - 2];
        if(now > MAX) break;
        fib.push_back(now);
        suf.push_back(suf[i - 1] + now);
    }
    fib.erase(fib.begin());
    reverse(all(fib));
    reverse(all(suf));
    solve();
    return 0;
}