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

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int x = 0;
    int y = 0;
    vector<int> dists;
    for(int i = 0;i < n;i++){
        int v;
        cin >> v;
        int dist = v - arr[i];
        if(v > arr[i]){
            y++;
            dists.push_back(dist);
        }else if(v < arr[i]){
            x++;
        }else{
            dists.push_back(dist);
        }
    }
    sort(all(dists));
    int ans = 0;
    int now = 0;
    while(x < y){
        if(dists[now] != 0){
            y--;
        }
        ans += dists[now] + 1;
        now++;
        x++;
    }
    if(x == y){
        if(dists[now]) ans += dists[now];
        else ans++;
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