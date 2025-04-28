/*11:51*/
#include <iostream>
#include <vector>
using namespace std;

int n, sum;
vector<int> v;
int ans = 0;

void dfs(int idx, long long cur){
    if(idx == n){
        if(cur == sum) ans++;
        return;
    }

    dfs(idx+1, cur + v[idx]);
    dfs(idx+1, cur);
}

int main(){
    cin >> n >> sum;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    dfs(0, 0);

    if(sum == 0) ans--;

    cout << ans;


}