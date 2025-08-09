#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int a,b;
    a = n;
    b = m;
    vector<bool> vist1 (n);
    vector<bool> vist2 (m);
    unordered_map<int,bool> vist3;
    unordered_map<int,bool> vist4;
    int ans = n * m;
    while(k--){
        int x,y;
        cin >> x >> y;
        if(!vist1[x]){
            for(int i = 1;i <= m;i++){
                if(!vist2[i] && !vist3[x - i] && !vist4[x + i]){
                    ans--;
                }
            }
        }
        if(!vist2[y]){
            for(int i = 1;i <= n;i++){
                if(i != x && !vist1[i] && !vist3[i - y] && !vist4[i + y]){
                    ans--;
                }
            }
            
        }
        int tmpx,tmpy;
        if(!vist3[x - y]){
            tmpx = x - 1;
            tmpy = y - 1;
            while(tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m){
                if(!vist1[tmpx] && !vist2[tmpy] && !vist4[tmpx + tmpy]){
                    ans--;
                }
                tmpx--;
                tmpy--;
            }
            tmpx = x + 1;
            tmpy = y + 1;
            while(tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m){
                if(!vist1[tmpx] && !vist2[tmpy] && !vist4[tmpx + tmpy]){
                    ans--;
                }
                tmpx++;
                tmpy++;
            }
        }
        if(!vist4[x + y]){
            tmpx = x + 1;
            tmpy = y - 1;
            while(tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m){
                if(!vist1[tmpx] && !vist2[tmpy] && !vist3[tmpx - tmpy]){
                    ans--;
                }
                tmpx++;
                tmpy--;
            }
            tmpx = x - 1;
            tmpy = y + 1;
            while(tmpx >= 1 && tmpx <= n && tmpy >= 1 && tmpy <= m){
                if(!vist1[tmpx] && !vist2[tmpy] && !vist3[tmpx - tmpy]){
                    ans--;
                }
                tmpx--;
                tmpy++;
            }
        }
        vist1[x] = true;
        vist2[y] = true;
        vist3[x - y] = true;
        vist4[x + y] = true;
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