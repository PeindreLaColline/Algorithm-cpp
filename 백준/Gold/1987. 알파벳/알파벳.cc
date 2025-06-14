/*1:00*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<string> board;
vector<bool> visited(26, false);

int ans = 0;

void bfs(int cx, int cy, int cnt){
    ans = max(ans, cnt);

    for(int i =0; i<4; i++){
        int nx = cx + dir[i][0];
        int ny = cy + dir[i][1];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(visited[board[ny][nx] - 'A']) continue;

        visited[board[ny][nx] - 'A'] = true;
        bfs(nx, ny, cnt+1);
        visited[board[ny][nx] - 'A'] = false;
    }
}

int main(){
    cin >> n >> m;

    board.resize(n);
    for(int i =0; i<n; i++){
        cin >> board[i];
    }
    visited[board[0][0] - 'A'] = true;

    bfs(0, 0, 1);

    cout << ans;
}