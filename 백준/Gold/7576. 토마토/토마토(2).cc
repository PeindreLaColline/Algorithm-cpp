/*08:22*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<int> > map;

queue<pair<int, int> > togo;
queue<pair<int, int> > n_togo;
queue<pair<int, int> > emp;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool check(){
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}

void bfs(){
    togo = n_togo;
    n_togo = emp;

    while(!togo.empty()){
        int cx = togo.front().first;
        int cy = togo.front().second;
        togo.pop();

        for(int i =0; i<4; i++){
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(map[ny][nx] != 0) continue;

            map[ny][nx] = 1;
            n_togo.push(make_pair(nx, ny));
        }
        
    }
}

int main(){

    cin >> m >> n;

    map.resize(n, vector<int>(m));
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) n_togo.push(make_pair(j, i));
        }
    }

    int ans = 0;
    while(!n_togo.empty()){
        ans++;
        bfs();
    }

    if(check()) cout << ans -1;
    else cout << -1;

}
