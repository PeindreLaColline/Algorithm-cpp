/*19:11*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int> > map;
vector<bool> visited;

queue<int> q;

void bfs(int s){
   while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i =1; i<=n; i++){
            if(i==s) continue;
            if(map[s][i] > map[s][cur] + map[cur][i]){
                map[s][i] = map[s][cur] + map[cur][i];
                q.push(i);
            }
        }
   }
}

int main(){
    cin >> n >> m;

    map.resize(n+1, vector<int>(n+1, 987654321));
    visited.resize(n+1, false);

    int a, b;
    for(int i =0; i<m; i++){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    for(int i=1; i<=n; i++){
        while(!q.empty()) q.pop();
        for(int j = 1; j<=n; j++){
            if(map[i][j] == 1) q.push(j);
        }
        bfs(i);
    }

    int min_num = 987654321;
    int min_per = 0;

    // for(int i =1; i<=n; i++){
    //     for(int j = 1; j<=n; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int tmp;
    for(int i =1; i<=n; i++){
        tmp = 0;
        for(int j = 1; j<=n; j++){
            if(i==j) continue;
            tmp += map[i][j];
        }
        if(tmp < min_num){
            min_num = tmp;
            min_per = i;
        }
    }

    cout << min_per;
}