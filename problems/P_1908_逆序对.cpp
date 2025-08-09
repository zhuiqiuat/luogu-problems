#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

const int N = 5e5 + 50;

long long help[N] = {0};

void merge(vector<long long>& arr,int l,int m,int r){
    int a = l;
    int b = m + 1;
    int c = l;
    while(a <= m && b <= r){
        help[c++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while(a <= m){
        help[c++] = arr[a++];
    }
    while(b <= r){
        help[c++] = arr[b++];
    }
    while(l <= r){
        arr[l++] = help[l];
    }
}

long long ans = 0;

void mergesort(vector<long long>& a,int l,int r){
    if(l == r){
        return;
    }
    int m = (l + r) >> 1;
    // cout << "l = " << l << " r = " << r << " m = " << m << "\n";
    mergesort(a,l,m);
    mergesort(a,m + 1,r);
    int x = l;
    int y = m + 1;
    while(x <= m){
        while(y <= r && a[y] < a[x]){
            y++;
        }
        ans += y - m - 1;
        x++;
    }
    merge(a,l,m,r);
}

void solve(){
    int n;
    cin >> n;
    vector<long long> a (n);
    for(auto& x : a){
        cin >> x;
    }
    mergesort(a,0,n - 1);
    // for(auto& x : a){
    //     cout << x << " ";
    // }
    // cout << "\n";
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