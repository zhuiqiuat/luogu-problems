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
    stack<int> st;
    vector<int> ans (n,-1);
    for(int i = 0;i < n;i++){
        while(st.size() && a[st.top()] < a[i]){
            int ind = st.top();
            st.pop();
            ans[ind] = i;
        }
        st.push(i);
    }
    for(int i = 0;i < n;i++){
        cout << ans[i] + 1 << " ";
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