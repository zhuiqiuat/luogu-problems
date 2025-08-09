#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<long long> ans (n,0);
    vector<long long> h (n);
    vector<long long> v (n);
    vector<int> left (n,-1);
    vector<int> right (n,-1);
    for(int i = 0;i < n;i++){
        cin >> h[i] >> v[i];
    }
    stack<int> st;
    for(int i = 0;i < n;i++){
        while(st.size() && h[st.top()] <= h[i]){
            int ind = st.top();
            st.pop();
            left[ind] = st.empty() ? -1 : st.top();
            right[ind] = i;
        }
        st.push(i);
    }
    while(st.size()){
        int ind = st.top();
        st.pop();
        left[ind] = st.empty() ? -1 : st.top();
        right[ind] = -1;
    }
    for(int i = n - 1;i >= 0;i--){
        if(h[right[i]] == h[i]){
            right[i] = right[right[i]];
        }
    }
    for(int i = 0;i < n;i++){
        if(left[i] != -1){
            ans[left[i]] += v[i];
        }
        if(right[i] != -1){
            ans[right[i]] += v[i];
        }
    }
    cout << *max_element(all(ans));
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