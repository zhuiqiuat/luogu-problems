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
    vector<ll> arr (n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i < n;i++){
        int num = i + 1;
        int cnt = arr[i];
        while(cnt > 0 && num >= 10){
            int tmp = 0;
            while(num > 0){
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
            cnt--;
        }
        cout << num << " ";
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