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

int f(vector<int>& a,int m){
    int ans = 0;
    for(int i = 1;i < a.size();i++){
        int d = a[i] - a[i - 1] - 1;
        ans += d / m;
    }
    return ans;
}

void solve(){
    int L,n,k;
    cin >> L >> n >> k;
    vector<int> a (n);
    for(auto& x : a){
        cin >> x;
    }
    int mx = -1;
    for(int i = 1;i < n;i++){
        mx = max(mx,a[i] - a[i - 1]);
    }
    int l = 1;
    int r = mx;
    int ans = 0;
    while(l <= r){
        int m = l + ((r - l) >> 1);
        if(f(a,m) <= k){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
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