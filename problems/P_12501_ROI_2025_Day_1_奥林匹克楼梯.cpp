#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define srt(a) sort(all(a));
#define MX(a) *max_element(all(a));
#define MN(a) *min_element(all(a));
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n,m;
    cin >> n >> m;
    cin.get();
    vector<vector<char>> graph (n + 1,vector<char> (m + 1));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> graph[i][j];
        }
    }
    vector<int> dp (n + 1,0);
    int ans = 0;
    vector<pair<int,int>> st (n);
    int r;
    for(int j = m;j >= 1;j--){
        for(int i = 1;i <= n;i++){
            if(graph[i][j] == '1'){
                dp[i]++;
            }else{
                dp[i] = 0;
            }
        }
        r = 0;
        for(int i = 1;i <= n;i++){
            while(r > 0 && dp[st[r - 1].first] > dp[i]){
                r--;
            }
            int cnt = r > 0 ? st[r - 1].second : 0;
            int left = r > 0 ? st[r - 1].first : 0;
            int now = cnt + (i - left) * dp[i];
            st[r++] = {i,now};
            ans = max(ans,now);
        }

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