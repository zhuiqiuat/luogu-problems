#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

const long long MOD = 1e9 + 7;

const int N = 1e6 + 50;
const int OFFSET = 30050;

vector<long long> arr (OFFSET + N + OFFSET,0);

void add(int l,int r,int a,int e,int d){
    arr[l] += a;
    // cout << "l = " << l << "\n";
    // cout << "a = " << a << "\n";
    arr[l + 1] -= a - d;
    arr[r + 1] -= d + e;
    arr[r + 2] += e;
}

void fall(int v,int x){
    add(x + OFFSET - 2 * v + 1,x + OFFSET,v - 1,-v,-1);
    add(x + OFFSET - 3 * v,x + OFFSET - 2 * v,0,v,1);
    add(x + OFFSET + 1,x + OFFSET + 2 * v - 1,-v + 1,v - 1,1);
    add(x + OFFSET + 2 * v,x + OFFSET + 3 * v,v,0,-1);
}

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int v,x;
        cin >> v >> x;
        fall(v,x);
    }
    // for(int i = OFFSET + 1;i <= OFFSET  + m;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    for(int i = 1;i < OFFSET * 2 + N;i++){
        arr[i] += arr[i - 1];
    }
    // for(int i = OFFSET + 1;i <= OFFSET  + m;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    for(int i = 1;i < OFFSET * 2 + N;i++){
        arr[i] += arr[i - 1];
    }
    // cout << OFFSET + 1 << "\n";
    for(int i = OFFSET + 1;i <= OFFSET  + m;i++){
        cout << arr[i] << " ";
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