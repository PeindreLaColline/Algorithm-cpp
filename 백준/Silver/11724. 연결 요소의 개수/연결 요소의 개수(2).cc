/*19:04*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<bool> visited;
vector<vector<int> > map;

void dfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i =0; i<map[cur].size(); i++){
            int nex = map[cur][i];
            if(!visited[nex]){
                visited[nex] = true;
                q.push(nex);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    visited.resize(n+1, false);
    map.resize(n+1, vector<int>());

    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int ans = 0;
    for(int i =1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }

    cout << ans;
}
