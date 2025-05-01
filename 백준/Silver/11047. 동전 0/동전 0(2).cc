/*01:44*/
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

int ans = 987654321;
void dfs(int idx, int val, int cnt){
    if(val == 0){
        ans = min(ans, cnt);
        return;
    }
    else if(val < 0 ) return;
    if(idx < 0) return;
    if(cnt > ans) return;

    for(int i = val/v[idx]; i>=0; i--){
        if(cnt+i > ans) return;
        dfs(idx-1, val-v[idx]*i, cnt+i);
    }
}

int main(){
    cin >> n >> k;

    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    dfs(n-1, k, 0);

    cout << ans;



}
