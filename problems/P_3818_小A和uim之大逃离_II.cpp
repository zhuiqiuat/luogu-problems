#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

struct status {
    int x,y;
    bool magic = false;
};

int dir[4][2] = {1,0,0,1,-1,0,0,-1};

void solve(){
    int n,m,d,r;
    cin >> n >> m >> d >> r;
    vector<vector<char>> graph (n,vector<char> (m));
    vector<vector<vector<bool>>> vist (n,vector<vector<bool>> (m,vector<bool> (2,false)));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> graph[i][j];
        }
    }
    vist[0][0][0] = true;
    queue<status> q;
    q.push({0,0,false});
    int ans = 0;
    while(q.size()){
        int s = q.size();
        while(s--){
            status now = q.front();
            q.pop();
            if(now.x == n - 1 && now.y == m - 1){
                cout << ans;
                return;
            }
            // cout << "nowx = " << now.x << " ";
            // cout << "nowy = " << now.y << "\n";
            // cout << "now.magic = " << now.magic << "\n";
            if(!now.magic){
                int newx = now.x + d;
                int newy = now.y + r;
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && graph[newx][newy] != '#' && !vist[newx][newy][1]){
                    vist[newx][newy][1] = true;
                    q.push({newx,newy,true});
                }
            }
            for(int i = 0;i < 4;i++){
                int newx = now.x + dir[i][0];
                int newy = now.y + dir[i][1];
                if(now.magic){
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && graph[newx][newy] != '#' && !vist[newx][newy][1]){
                        vist[newx][newy][1] = true;
                        q.push({newx,newy,now.magic});
                    }
                }else{
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && graph[newx][newy] != '#' && !vist[newx][newy][0]){
                        vist[newx][newy][0] = true;
                        q.push({newx,newy,now.magic});
                    }
                }
            }
        }
        ans++;
    }
    // cout << "ans = " << ans << "\n";
    cout << -1;
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