#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fastpow(ll a,ll b,ll mod);
bool isprime(ll n);

ll mod = 1145141923;

void solve(){
    ll n,m;
    cin >> n >> m;
    ll count = m;
    ll ans = 1;
    ll zero = 0;
    set<ll> tmp;
    for(int i = 1;i <= n;i++){
        ll x;
        cin >> x;
        if(x == 0){
            zero++;
        }else{
            tmp.insert(x);
            if(x <= m){
                count--;
            }
        }
    }
    if(zero > count || tmp.size() != n - zero){
        cout << 0;
        return;
    }
    for(int i = 1;i <= zero;i++){
        ans *= count;
        ans %= mod;
        count--;
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
        // cout << 0;
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