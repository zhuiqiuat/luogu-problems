#include <bits/stdc++.h>
using namespace std;
struct status {
    int u;
    int k = 0;
    int cost = 0;
};

struct cmp {
    bool operator() (status s1,status s2){
        return s1.cost > s2.cost;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	int s,t;
	cin >> s >> t;
	vector<vector<pair<int,int>>> graph (n);
	for(int i = 0;i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w}); 
	}
	bool vist[n][k + 5] = {0};
    vector<vector<int>> ans (n,vector<int> (k + 5,INT_MAX));
	ans[s][0] = 0;
	priority_queue<status,vector<status>,cmp> pq;
    pq.push({s,0,0});
    while(pq.size()){
        status now = pq.top();
        pq.pop();
        if(vist[now.u][now.k]) continue;
        vist[now.u][now.k] = true;
        if(now.u == t){
            cout << now.cost;
            return 0;
        }
        for(int i = 0;i < graph[now.u].size();i++){
            int to = graph[now.u][i].first;
            int cost = graph[now.u][i].second;
            if(now.k < k){
                if(ans[to][now.k + 1] > now.cost){
                    ans[to][now.k + 1] = now.cost;
                    pq.push({to,now.k + 1,now.cost});
                }
            }
            if(ans[to][now.k] > ans[now.u][now.k] + cost){
                ans[to][now.k] = ans[now.u][now.k] + cost;
                pq.push({to,now.k,ans[to][now.k]});
            }
        }
    }
	return 0;
}