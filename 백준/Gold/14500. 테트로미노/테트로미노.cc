/*18:24*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m;
vector<vector<int> > v;
vector<vector<bool> > visited;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int ans = 0;

void dfs(int cnt, int val, pair<int, int> po){
    if(cnt == 4){
        ans = max(ans, val);
        return;
    }

    int cx = po.first;
    int cy = po.second;

    for(int i =0; i<4; i++){

        int nx = cx + dir[i][0];
        int ny = cy + dir[i][1];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(visited[ny][nx]) continue;
        
        visited[ny][nx] = true;
        dfs(cnt+1, val + v[ny][nx], make_pair(nx, ny));
        visited[ny][nx] = false;
    }
}

void checkTShape(int y, int x) {
    // ㅗ, ㅜ, ㅓ, ㅏ 총 4가지 모양
    int tShape[4][3][2] = {
        {{0,1}, {0,-1}, {-1,0}},  // ㅗ
        {{0,1}, {0,-1}, {1,0}},   // ㅜ
        {{-1,0}, {1,0}, {0,-1}},  // ㅓ
        {{-1,0}, {1,0}, {0,1}}    // ㅏ
    };

    for (int i = 0; i < 4; i++) {
        int sum = v[y][x];
        bool valid = true;

        for (int j = 0; j < 3; j++) {
            int ny = y + tShape[i][j][0];
            int nx = x + tShape[i][j][1];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                valid = false;
                break;
            }
            sum += v[ny][nx];
        }

        if (valid) ans = max(ans, sum);
    }
}

int main(){
    cin >> n >> m;
    v.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> v[i][j];
        }
    }

    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            visited[i][j] = true;
            dfs(1, v[i][j], make_pair(j, i));
            visited[i][j] = false;
            checkTShape(i, j);
            
        }
    }

    cout << ans;

}