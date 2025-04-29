/*17:08*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, l, r;
vector<vector<int> > map;
vector<vector<int> > map2;
vector<vector<bool> > visited;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool done;

void bfs(pair<int, int> po){
    stack<pair<int, int> > s;
    stack<pair<int, int> > went;
    s.push(po);
    went.push(po);

    int peo = map[po.second][po.first];
    int cnt = 1;
    
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        s.pop();

        for(int i =0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[ny][nx]) continue;
            int dif = abs(map[y][x] - map[ny][nx]);
            if(dif < l || dif > r) continue;

            visited[ny][nx] = true;
            cnt++;
            peo += map[ny][nx];
            s.push(make_pair(nx, ny));
            went.push(make_pair(nx, ny));
            done = true;
        }
    }

    while(!went.empty()){
        int x = went.top().first;
        int y = went.top().second;

        map2[y][x] = peo/cnt;
        went.pop();
    }
}

int main(){
    cin >> n >> l >> r;
    map.resize(n, vector<int>(n, 0));
    map2.resize(n, vector<int>(n, 0));
    visited.clear();
    visited.resize(n, vector<bool>(n, false));
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> map[i][j];
        }
    }

    int day = 0;

    while(true){
        done = false; 
         
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j]){
                    visited[i][j] = true;
                    bfs(make_pair(j, i));
                }
            }
        }

        // for(int i =0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout << map2[i][j]<<" ";
        //     }
        //     cout << endl;
        // }
        if(done){
            day++;
            visited.clear();
            visited.resize(n, vector<bool>(n, false));
            map = map2;
        }
        else{
            break;
        }
    }

    cout << day;
}