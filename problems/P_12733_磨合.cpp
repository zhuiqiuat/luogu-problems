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

void solve(){
    int n,q;
    cin >> n >> q;
    vector<ll> a (n);
    for(auto& x : a){
        cin >> x;
    }
    sort(all(a));
    for(int i = 1;i < n;i++){
        a[i] += a[i - 1];
    }
    for(int i = 1;i < n;i++){
        a[i] += a[i - 1];
    }
    while(q--){
        ll x;
        cin >> x;
        cout << upper_bound(all(a),x) - a.begin() << "\n";
    }
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