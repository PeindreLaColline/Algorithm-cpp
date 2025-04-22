/*19:24*/
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int n, m;
vector<bool> visited;
vector<vector<int> > map;

void dfs(int po){
    queue<int> togo;
    togo.push(po);

    while(!togo.empty()){
        int cur = togo.front();
        togo.pop();
        
        for(int i =0; i<map[cur].size(); i++){
            if(visited[map[cur][i]]) continue;
            visited[map[cur][i]] = true;
            togo.push(map[cur][i]);
        }
    }
}

int main(){
    // init
    cin >> n >> m;
    visited.resize(n, false);
    map.resize(n);

    // input
    int a, b;
    for(int i =0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // dfs
    int ans = 0;
    for(int i =0; i<n; i++){
        if(!visited[i]){
            ans++;
            visited[i] = true;
            dfs(i);
        }
    }

    // output
    cout << ans;
}