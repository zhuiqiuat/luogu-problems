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
    int n,m,k;
    cin >> n >> m >> k;
    if((n - m) > m * k || n - m < k){
        cout << -1;
        return;
    }
    vector<int> a (m);
    vector<bool> vist (n + 1,false);
    vector<int> cnt (n + 1,0);
    for(int i = 0;i < m;i++){
        cin >> a[i];
        vist[a[i]] = true;
    }
    int now = 0;
    int last = a[0];
    for(int i = 1;i <= n;i++){
        if(!vist[i]){
            cout << last << " " << i << "\n";
            last = i;
            cnt[now]++;
            if(cnt[now] == k){
                cout << last << " " << a[now] << "\n";
                now++;
                last = a[now];
            }
        }
    }
    for(;now < m;now++){
        if(cnt[now] != 0){
            cout << last << " " << a[now] << "\n";
        }else{
            cout << a[now] << " " << a[0] << "\n";
        }
    }
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