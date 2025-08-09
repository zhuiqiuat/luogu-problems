#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n,m;
    cin >> n >> m;
    int graph[n + 5][n + 5];
    ll floyd[n + 5][n + 5];
    ll cnt[n + 5][n + 5] = {0};
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cnt[i][j] = 1;
        }
    }
    memset(graph,0x3f,sizeof(graph));
    memset(floyd,0x3f,sizeof(floyd));
    for(int i = 0;i < m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j) continue;
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }else if(graph[i][j] == graph[i][k] + graph[k][j]){
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                }
            }
        }
    }
    for(int k = 1;k <= n;k++){
        double ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == k || j == k) continue;
                if(graph[i][j] == graph[i][k] + graph[k][j]) ans += cnt[i][k] * cnt[k][j] * 1.0 / cnt[i][j];
            }
        }
        printf("%.3lf\n",ans);
    }
}

int main(){
    solve();
    return 0;
}