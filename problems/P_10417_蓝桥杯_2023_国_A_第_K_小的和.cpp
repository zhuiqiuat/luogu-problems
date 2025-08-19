#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fr first
#define sc second
#define sz(x) (x).size()
#define all(a) (a).begin(),(a).end()
#define srt(a) sort(all(a));
#define MX(a) *max_element(all(a));
#define MN(a) *min_element(all(a));

const long long MOD = 1e9 + 7;

ll f(ll m,vector<ll>& a,vector<ll>& b){
    ll cnt = 0;
    for(auto& x : a){
        ll n = m - x;
        cnt += upper_bound(all(b),n) - b.begin();
    }
    return cnt;
}

void solve(){
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a (n);
    vector<ll> b (m);
    for(auto& x : a){
        cin >> x;
    }
    for(auto& x : b){
        cin >> x;
    }
    srt(a);
    srt(b);
    ll l = a[0] + b[0];
    ll r = a[n - 1] + b[m - 1];
    ll ans = 0;
    while(l <= r){
        ll m = l + ((r - l) >> 1);
        if(f(m,a,b) >= k){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}