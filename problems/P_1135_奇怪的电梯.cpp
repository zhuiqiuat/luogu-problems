#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

const long long MOD = 1e9 + 7;

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> arr (n + 5);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    queue<int> q;
    vector<bool> vist (n + 5);
    q.push(a);
    vist[a] = true;
    int ans = 0;
    while(q.size()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            int now = q.front();
            q.pop();
            if(now == b){
                cout << ans;
                return;
            }
            int up = now + arr[now];
            int down = now - arr[now];
            if(up <= n && !vist[up]){
                q.push(up);
                vist[up] = true;
            }
            if(0 < down && !vist[down]){
                q.push(down);
                vist[down] = true;
            }
        }
        ans++;
    }
    cout << -1;
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