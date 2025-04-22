/*19:24*/
/*
배열에 연결 정보 저장 (1-2가 연결되어있다면 map[1]에 2넣고, map[2]에 1 넣어서 양방향으로 저장)
visited 배열 확인하면서 dfs 순회
dfs 함수 호출 횟수가 연결 요소 개수
*/
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
