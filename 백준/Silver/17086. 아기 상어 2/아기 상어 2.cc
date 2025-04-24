/*10:58*/
/*
상어가 있는 칸에서부터 모든 칸까지의 거리를 순회함
순회할 때 현재 dist보다 큰 게 있으면 togo에 넣고 아니면 무시
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<vector<int> > map;

int dir[8][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1},
    {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
};

int ans = 0;

int bfs(pair<int, int> po){
    stack<pair<int, int> > n_togo;
    n_togo.push(po);

    int dist = 1;
    while(!n_togo.empty()){
        stack<pair<int, int> > togo;
        togo = n_togo;
        while(!n_togo.empty()) n_togo.pop();

        while(!togo.empty()){
            int x = togo.top().first;
            int y = togo.top().second;
            togo.pop();

            for(int i =0; i<8; i++){
                int cx = x + dir[i][0];
                int cy = y + dir[i][1];
                if(cx < 0 || cy < 0 || cx >= m || cy >= n) continue;
                if(map[cy][cx] > dist){
                    map[cy][cx] = dist;
                    n_togo.push(make_pair(cx, cy));
                }
            }

        }
        dist++;
        
    }
    return dist;
}

int main(){
    cin >> n >> m;
    vector<int> itmp(m, false);
    map.resize(n, itmp);
    stack<pair<int, int> > s;

    int tmp;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> tmp;
            if(tmp == 1){
                map[i][j] = -1;
                s.push(make_pair(j, i));
            }
            else map[i][j] = 98765432;
        }
    }

    while(!s.empty()){
        bfs(make_pair(s.top().first, s.top().second));
        s.pop();
    }

    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans = max(ans, map[i][j]);
        }
    }

    cout << ans;
}