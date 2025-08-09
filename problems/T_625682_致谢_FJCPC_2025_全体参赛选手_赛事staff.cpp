#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

const long long MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<string> v (12);
    v[1] = "FZU";
    v[2] = "FNU";
    v[3] = "FZU";
    v[4] = "FZU";
    v[5] = "FAFU";
    v[6] = "HQU";
    v[7] = "MJU";
    v[8] = "XMUT";
    v[9] = "QNU";
    v[10] = "JMU";
    v[11] = "FZU";
    cout << v[n];
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