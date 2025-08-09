#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

bool cmp(pair<long long,long long> p1,pair<long long,long long> p2){
    return p1.first < p2.first;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<long long,long long>> a (n);
    for(int i = 0;i < n;i++){
        cin >> a[i].first >> a[i].second;
    }
    a.push_back({1e15,1e15});
    sort(all(a),cmp);
    long long ans = 0;
    long long l = a[0].first;
    long long r = a[0].second;
    for(int i = 1;i < a.size();i++){
        long long x = a[i].first;
        long long y = a[i].second;
        if(x <= r){
            r = max(r,y);
        }else{
            ans += r - l;
            l = x;
            r = y;
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