#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

struct cmp {
    bool operator() (pair<int,long long> p1,pair<int,long long> p2){
        return p1.second > p2.second;
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,long long>>> graph (n);
    unordered_map<string,int> mp;
    int ind = 0;
    for(int i = 0;i < m;i++){
        string s1,s2;
        long long w;
        cin >> s1 >> s2 >> w;
        if(mp.find(s1) == mp.end()){
            mp[s1] = ind++;
        }
        if(mp.find(s2) == mp.end()){
            mp[s2] = ind++;
        }
        int u = mp[s1];
        int v = mp[s2];
        graph[u].push_back({v,w});
    }
    int q;
    cin >> q;
    while(q--){
        string s1,s2;
        cin >> s1 >> s2;
        vector<bool> vist (n,0);
        vector<long long> dis (n,LLONG_MAX);
        int u = mp[s1];
        int v = mp[s2];
        dis[u] = 0;
        priority_queue<pair<int,long long>,vector<pair<int,long long>>,cmp> pq;
        pq.push({u,0});
        while(pq.size()){
            int now = pq.top().first;
            pq.pop();
            if(vist[now]){
                continue;
            }
            vist[now] = true;
            for(auto& [to,cost] : graph[now]){
                if(dis[now] + cost < dis[to]){
                    dis[to] = dis[now] + cost;
                    pq.push({to,dis[to]});
                }
            }
        }
        if(dis[v] == LLONG_MAX){
            cout << "Roger\n";
        }else{
            cout << dis[v] << "\n";
        }
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