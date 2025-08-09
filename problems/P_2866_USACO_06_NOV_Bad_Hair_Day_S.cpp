#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<long long> a (n);
    for(auto& x : a){
        cin >> x;
    }
    long long ans = 0;
    stack<int> st;
    for(int i = n - 1;i >= 0;i--){
        while(st.size() && a[st.top()] < a[i]){
            int ind = st.top();
            st.pop();
            ans += st.empty() ? n - ind - 1 : st.top() - ind - 1;
        }
        st.push(i);
    }
    while(st.size()){
        int ind = st.top();
        st.pop();
        ans += st.empty() ? n - ind - 1 : st.top() - ind - 1;
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