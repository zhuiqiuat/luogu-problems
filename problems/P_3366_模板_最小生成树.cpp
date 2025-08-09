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
    }
}

const long long MOD = 1e9 + 7;

struct bian {
    int v,w;
    int c;
};

bool cmp(bian b1,bian b2){
    return b1.c < b2.c;
}

void solve(){
    int n,m;
    cin >> n >> m;
    builddsu(n);
    vector<bian> bians;
    for(int i = 0;i < m;i++){
        int v,w,c;
        cin >> v >> w >> c;
        bians.push_back({v,w,c});
    }
    sort(all(bians),cmp);
    int ans = 0;
    int cnt = 0;
    for(int i = 0;i < m;i++){
        if(find(bians[i].v) != find(bians[i].w)){
            uni(bians[i].v,bians[i].w);
            ans += bians[i].c;
            cnt++;
        }
    }
    cout << (cnt == n - 1 ? to_string(ans) : "orz");
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