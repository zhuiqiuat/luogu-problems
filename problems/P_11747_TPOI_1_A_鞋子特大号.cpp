#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll fastpow(ll a,ll b,ll mod);
ll isprime(ll n);

ll mod = 1e9 + 7;
const ll MAX = 1e6 + 50;

// int arr[MAX] = {0};

void solve(){
    int x,q;
    cin >> x >> q;
    if(x == 1){
        int tmp = q;
        int count = 0;
        while(isprime(tmp) != 1){
            tmp /= isprime(tmp);
            count++;
        }
        cout << count << "\n";
    }else if(x == 2){
        cout << fastpow(2,q + 1,0) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
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

ll isprime(ll n){
    if(n <= 3) return 1;
    if(n % 2 == 0) return 2;
    if(n % 3 == 0) return 3;
    for(ll i = 5;i * i <= n;i += 6){
        if(n % i == 0) return i;
        if(n % (i + 2) == 0) return i + 2;
    }
    return 1;
}