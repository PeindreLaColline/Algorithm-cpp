#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans = 300001;
vector<int> card;
vector<bool> visited;

void dfs(int dep, int sum, int ind){
    if(dep == 3){
        if((abs(ans - m) > abs(sum - m)) && sum <= m){
            ans = sum;
        }
        return;
    }

    for(int i = ind; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(dep+1, sum+card[i], i+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    card.resize(n);
    visited.resize(n, false);

    for(int i =0; i<n; i++){
        cin >> card[i];
    }

    dfs(0, 0, 0);

    cout << ans << endl;
}
