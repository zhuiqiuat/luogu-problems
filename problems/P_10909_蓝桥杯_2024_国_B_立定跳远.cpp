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

bool f(vector<int>& a,int& l,int& m){
    int ans = 0;
    int last = 0;
    for(auto& x : a){
        // cout << "last = " << last << "\n";
        // cout << "x = " << x << "\n";
        // cout << "ans = " << (x - last - 1) / l << "\n";
        // cout << "l = " << l << "\n";
        ans += (x - last - 1) / l;
        last = x;
    }
    return ans - 1 <= m;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a (n);
    for(auto& x : a){
        cin >> x;
    }
    int ans = -1;
    int l = 1;
    int r = 1e8;
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        if(f(a,mid,m)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
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