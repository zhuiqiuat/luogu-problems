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
    ll a,b,p;
    cin >> a >> b >> p;
    if(p - a > b){
        cout << a << " " << b;
        return;
    }
    ll mina = a;
    ll minb = b;
    b -= p - a;
    a = 0;
    if(a < mina){
        mina = a;
        minb = b % p;
    }
    cout << mina << " " << minb;
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