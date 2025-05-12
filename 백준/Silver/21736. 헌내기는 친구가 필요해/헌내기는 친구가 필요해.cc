/*16:36*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int n, m;
vector<vector<int> > map;
vector<vector<bool> > visited;
stack<pair<int, int> > togo;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int ans = 0;

void bfs(){
    while(!togo.empty()){
        int cx = togo.top().first;
        int cy = togo.top().second;
        togo.pop();

        for(int i =0; i<4; i++){
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
        
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(visited[ny][nx] || map[ny][nx] == -1) continue;
            if(map[ny][nx] == 1) ans++;
            togo.push(make_pair(nx, ny));
            visited[ny][nx] = true;
        }
    }
}

int main(){
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    string input;

    int x, y;
    for(int i =0; i<n; i++){
        cin >> input;
        for(int j = 0; j<m; j++){
            if(input[j] == 'O'){
                map[i][j] = 0;
            }
            else if(input[j] == 'X'){
                map[i][j] = -1;
            }
            else if(input[j] == 'P'){
                map[i][j] = 1;
            }
            else{
                map[i][j] = 0;
                visited[i][j] = true;
                togo.push(make_pair(j, i));
            }
        }
    }

    bfs();

    if(ans == 0){
        cout << "TT";
    }
    else{
        cout << ans;
    }
}