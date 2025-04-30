/*16:06*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<vector<int>> map;
vector<vector<vector<int>>> route; // route[y][x][0 or 1] -> distance

void bfs(){
    queue<tuple<int, int, int>> q; // x, y, broken
    q.push({0, 0, 0});
    route[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            // 빈 칸
            if (map[ny][nx] == 0 && route[ny][nx][broken] > route[y][x][broken] + 1) {
                route[ny][nx][broken] = route[y][x][broken] + 1;
                q.push({nx, ny, broken});
            }

            // 벽인데 아직 안 부쉈을 때만
            if (map[ny][nx] == 1 && broken == 0 && route[ny][nx][1] > route[y][x][0] + 1) {
                route[ny][nx][1] = route[y][x][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
}

int main(){
    cin >> n >> m;

    map.resize(n, vector<int>(m));
    route.resize(n, vector<vector<int>>(m, vector<int>(2, 987654321)));

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    bfs();

    int result = min(route[n-1][m-1][0], route[n-1][m-1][1]);

    if (result == 987654321) {
        cout << -1;
    } else {
        cout << result;
    }
}