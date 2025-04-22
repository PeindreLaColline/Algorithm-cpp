/*18:58*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int test_case;
int m, n, k;

vector<bool> btmp;
vector<vector<bool> > map;
vector<vector<bool> > visited;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(pair<int, int> s){
    queue<pair<int, int> > togo;
    togo.push(s);

    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();

        for(int i =0; i<4; i++){
            int cx = x + dir[i][0];
            int cy = y + dir[i][1];
            if(cx < 0 || cy < 0 || cx >= m || cy >= n) continue;
            if(visited[cy][cx] || !map[cy][cx]) continue;
            
            visited[cy][cx] = true;
            togo.push(make_pair(cx, cy));
        }
    }
}

int main(){
    cin>>test_case;
    for(int t = 0; t<test_case; t++){
        // init
        cin >> m >> n >> k;

        btmp.clear();
        map.clear();
        visited.clear();

        btmp.resize(m, false);
        map.resize(n, btmp);
        visited.resize(n, btmp);

        // input
        int x, y;
        for(int i = 0; i<k; i++){
            cin >> x >> y;
            map[y][x] = true;
        }

        // dfs
        int ans = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(map[i][j] && !visited[i][j]){
                    ans++;
                    visited[i][j] = true;
                    dfs(make_pair(j, i));
                }
            }
        }

        // output
        cout << ans << "\n";


    }
}