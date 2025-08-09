#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;


void solve(){
    int n,m;
    cin >> n >> m;
    vector<long long> a (n + 3,0);
    for(int i = 0;i < m;i++){
        int l,r;
        long long s,e;
        cin >> l >> r >> s >> e;
        long long d = (e - s) / (r - l);
        a[l] += s;
        a[l + 1] += d - s;
        a[r + 1] -= d + e;
        a[r + 2] += e;
    }
    for(int i = 1;i <= n;i++){
        a[i] += a[i - 1];
    }
    for(int i = 1;i <= n;i++){
        a[i] += a[i - 1];
    }
    long long ans = a[1];
    long long mx = a[1];
    for(int i = 2;i <= n;i++){
        ans ^= a[i];
        mx = max(mx,a[i]);
    }
    cout << ans << " " << mx;
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