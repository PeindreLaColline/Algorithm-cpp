//17:18
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<vector<int> > map;
vector<vector<int> > way;

queue<pair<int, int> > togo;
queue<pair<int, int> > n_togo;
queue<pair<int, int> > emp;

int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs(){
    while(!n_togo.empty()){
        togo = n_togo;
        n_togo = emp;

        while(!togo.empty()){
            int cx = togo.front().first;
            int cy = togo.front().second;
            togo.pop();

            for(int i =0; i<4; i++){
                int nx = cx + dir[i][0];
                int ny = cy + dir[i][1];

                if(nx >=0 && ny >=0 && nx < m && ny < n){
                    if(map[ny][nx] == 0) continue;
                    if(way[ny][nx] > way[cy][cx] + 1){
                        way[ny][nx] = way[cy][cx] + 1;
                        n_togo.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    way.resize(n, vector<int>(m, 98765432));

    string s;
 
    for(int i =0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    way[0][0] = 1;
    n_togo.push(make_pair(0, 0));

    bfs();
    cout << way[n-1][m-1];
    
    // for(int i =0; i<n; i++){
    //     for(int j =0; j<m; j++){
    //         cout << way[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}