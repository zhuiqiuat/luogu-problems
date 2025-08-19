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
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> dp (n + 1,vector<ll> (m + 1,LLONG_MAX)); // dp[i][j] 表示在第 j 天到达了 i 座城市需要最少的疲劳值;
    vector<ll> d (n + 1);
    vector<ll> c (m + 1);
    for(int i = 1;i <= n;i++){
        cin >> d[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> c[i];
    }
    for(int i = 1;i <= m;i++){
        dp[1][i] = min(dp[1][i - 1],d[1] * c[i]);
    }
    for(int i = 2;i <= n;i++){
        for(int j = i;j <= m;j++){
            dp[i][j] = min(dp[i][j - 1],dp[i - 1][j - 1] + c[j] * d[i]);
        }
    }
    cout << dp[n][m];
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