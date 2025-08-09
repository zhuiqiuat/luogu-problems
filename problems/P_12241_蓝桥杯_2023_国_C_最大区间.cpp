#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define srt(a) sort(all(a));
#define MX(a) *max_element(all(a));
#define MN(a) *min_element(all(a));
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
    long long ans = MX(a);
    for(int i = 0;i < n;i++){
        while(st.size() && a[st.top()] >= a[i]){
            int ind = st.top();
            st.pop();
            if(a[ind] != a[i]){
                int l = st.empty() ? -1 : st.top();
                long long len = i - l - 1;
                // cout << "l = " << l << "\n";
                // cout << "r = " << i << "\n";
                // cout << "ind = " << ind << "\n";
                // cout << "len = " << len << "\n";
                ans = max(ans,a[ind] * len);
            }
        }
        st.push(i);
    }
    while(st.size() ){
        int ind = st.top();
        st.pop();
        int l = st.empty() ? -1 : st.top();
        long long len = n - l - 1;
        ans = max(ans,a[ind] * len);
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