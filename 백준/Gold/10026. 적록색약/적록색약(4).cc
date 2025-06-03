/*20:52*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n;
vector<vector<int> > v1;
vector<vector<int> > v2;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void yes_blind(int color, pair<int, int> po){
    queue<pair<int, int> > togo;
    togo.push(po);
    
    while(!togo.empty()){
        int cx = togo.front().first;
        int cy = togo.front().second;
        togo.pop();

        for(int i =0; i<4; i++){
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(v2[ny][nx] != color) continue;
            v2[ny][nx] = -1;
            togo.push(make_pair(nx, ny));
        }
    }
}

void no_blind(int color, pair<int, int> po){
    queue<pair<int, int> > togo;
    togo.push(po);

    while(!togo.empty()){
        int cx = togo.front().first;
        int cy = togo.front().second;
        togo.pop();

        for(int i =0; i<4; i++){
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(v1[ny][nx] != color) continue;
            v1[ny][nx] = -1;
            togo.push(make_pair(nx, ny));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    v1.resize(n, vector<int>(n));
    v2.resize(n, vector<int>(n));

    string tmp;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        for(int j = 0; j<n; j++){
            v1[i][j] = tmp[j];
            v2[i][j] = tmp[j];
            if(v2[i][j] == 'R') v2[i][j] = 'G';
        }
    }

    int no = 0;
    int yes = 0;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(v1[i][j] != -1){
                no++;
                no_blind(v1[i][j], make_pair(j, i));
            }
            if(v2[i][j] != -1){
                yes++;
                yes_blind(v2[i][j], make_pair(j, i));
            }
        }
    }

    cout << no << " " << yes;


}
