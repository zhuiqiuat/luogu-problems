#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a (n + 2,vector<int> (n + 2,0));
    for(int i = 0;i < m;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x1][y2 + 1]--;
        a[x2 + 1][y1]--;
        a[x2 + 1][y2 + 1]++;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]; 
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
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