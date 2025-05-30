/*17:11*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct po{
    int x;
    int y;
    int z;

    po(int _x, int _y, int _z) : x(_x), y(_y), z(_z){}
};

int m, n, h;
vector<vector<vector<int> > > v;

queue<po> togo;
queue<po> n_togo;
queue<po> emp;

int dir[6][3] = {{0, 1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {0, 0, 1}}; // x y z

bool check(){
    for(int k = 0; k<h; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!v[k][i][j]) return false;
            }
        }
    }
    return true;
}

void bfs(){
    togo = n_togo;
    n_togo = emp;

    while(!togo.empty()){
        po cur = togo.front();
        togo.pop();

        for(int i =0; i<6; i++){
            po nex = po(cur.x + dir[i][0],  cur.y + dir[i][1], cur.z + dir[i][2]);

            if(nex.x < 0 || nex.x >= m
                || nex.y < 0 || nex.y >= n
                || nex.z < 0 || nex.z >= h
            ) continue;
            if(v[nex.z][nex.y][nex.x] == 0){
                n_togo.push(nex);
                v[nex.z][nex.y][nex.x] = 1;
            }
        }
    }
}

int main(){
    cin >> m >> n >> h;
    v.resize(h, vector<vector<int> >(n, vector<int>(m, 0)));

    //1익음 0안익음 -1없음
    for(int k = 0; k<h; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> v[k][i][j];
                if(v[k][i][j] == 1){
                    n_togo.push(po(j, i, k));
                }
            }
        }
    }

    int ans = -1;
    while(!n_togo.empty()){
        bfs();
        ans++;
    }
    if(check()){
        cout << ans;
    }
    else{
        cout << -1;
    }
    
}