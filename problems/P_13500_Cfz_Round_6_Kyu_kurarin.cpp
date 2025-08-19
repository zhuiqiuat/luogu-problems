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

ll f(vector<ll> a,ll m){
    ll ans = 0;
    for(auto& x : a){
        x -= m;
    }
    for(auto& x : a){
        if(x <= 0){
            ans += llabs(x) + 1;
        }
    }
    return ans;
}

void solve(){
    int n,k;
    cin >> n >> k;
    vector<ll> a (n);
    for(auto& x : a){
        cin >> x;
    }
    ll l = 0;
    ll r = 1e13;
    ll ans;
    while(l <= r){
        ll m = l + ((r - l) >> 1);
        if(f(a,m) <= k * m){
            l = m + 1;
            ans = m;
        }else{
            r = m - 1;
        }
    }
    cout << ans;
}

int main(){
    
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);
             
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}