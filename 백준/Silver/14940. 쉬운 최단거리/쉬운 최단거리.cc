/*20:33*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct po{
    int x;
    int y;
    int val;

    po(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {}
};

int n, m;
vector<vector<int> > map;


struct compare{
    bool operator()(const po &a, const po &b){
        return a.val > b.val;
    }
};
priority_queue<po, vector<po>, compare> pq;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void back(){
    while(!pq.empty()){
        po cur = pq.top();
        pq.pop();

        if(cur.val != map[cur.y][cur.x]) continue;

        for(int i =0; i<4; i++){
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(map[ny][nx] == 0) continue;
            else if(map[ny][nx] > cur.val + 1){
                map[ny][nx] = cur.val + 1;
                pq.push(po(nx, ny, map[ny][nx]));
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    map.resize(n, vector<int>(m));

    int tmp;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> tmp;
            if(tmp == 1){
                map[i][j] = 987654321;
            }
            else if(tmp == 0){
                map[i][j] = 0;
            }
            else{
                pq.push(po(j, i, 0));
                map[i][j] = 0;
            }
        }
    }

    back();

    for(int i = 0;i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 987654321) cout << -1 << ' ';
            else cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}