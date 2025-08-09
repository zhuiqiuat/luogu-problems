#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll fastpow(ll a,ll b,ll mod){
    ll ans = 1;
    if(mod != 0){
        a %= mod;
    }
    while(b > 0){
        if(b & 1){
            ans *= a;
            if(mod != 0){
                ans %= mod;
            }
        }
        a *= a;
        if(mod != 0){
            a %= mod;
        }
        b >>= 1;
    }
    return ans;
}

bool isprime(ll n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5;i * i <= n;i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

const int MAXDSU = 1e5;

vector<int> dsu (MAXDSU,0);
vector<int> dsusize (MAXDSU,0);
int mysize = 0;

void builddsu(int n){
    for(int i  = 1;i <= n;i++){
        dsu[i] = i;
        dsusize[i] = 1;
    }
}

int find(int x){
    queue<int> q;
    while(dsu[x] != x){
        q.push(x);
        x = dsu[x];
    }
    while(!q.empty()){
        dsu[q.front()] = x;
        q.pop();
    }
    return x;
}

void uni(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        dsu[fa] = fb;
        dsusize[fb] += dsusize[fa];
        mysize--;
    }
}

const long long MOD = 1e9 + 7;

struct edge {
    int num1,num2;
    double dist;
};

double distance(pair<int,int> p1,pair<int,int> p2){
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    double ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return ans;
}

bool cmp(edge e1,edge e2){
    return e1.dist < e2.dist;
}

void solve(){
    int n,k;
    cin >> n >> k;
    builddsu(n);
    mysize = n;
    vector<pair<int,int>> pos (n);
    for(int i = 0;i < n;i++){
        cin >> pos[i].first >> pos[i].second;
    }
    vector<edge> edges;
    for(int i = 0;i < pos.size();i++){
        for(int j = 0;j < pos.size();j++){
            if(i == j) continue;
            edges.push_back({i + 1,j + 1,distance(pos[i],pos[j])});
        }
    }
    sort(all(edges),cmp);
    int i;
    for(i = 0;i < edges.size() && mysize > k;i++){
        int u = edges[i].num1;
        int v = edges[i].num2;
        if(find(u) != find(v)){
            uni(u,v);
        }
    }
    while(i < edges.size() && find(edges[i].num1) == find(edges[i].num2)){
        i++;
    }
    if(i < edges.size()) printf("%.2lf",edges[i].dist);
    else cout << "0.00";
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}