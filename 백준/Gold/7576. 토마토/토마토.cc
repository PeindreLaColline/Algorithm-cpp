/*16:39*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int m, n;
vector<vector<int> > map;
queue<pair<int, int> > togo;
queue<pair<int, int> > n_togo;
int ans = 0;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int cnt = 0;

void print(){
    cout<<"trial"<<ans<<endl;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << map[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<endl;
}

void bfs(){
    
    while(!n_togo.empty()){
        
        togo = n_togo;
        while(n_togo.size()){
            n_togo.pop();
        }

        //print();

        while(!togo.empty()){

            int x = togo.front().second;
            int y = togo.front().first;
            togo.pop();
            

            for(int i =0; i<4; i++){
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];
                if(nx<0 || ny <0 || nx>=m || ny >= n) continue;
                if(map[ny][nx] == 0){
                    map[ny][nx] = 1;
                    n_togo.push(make_pair(ny, nx));
                    cnt--;
                }
            }
        }
        if(n_togo.size()) ans++;
        
    }

}

int main(){
    
    cin >>m>>n;
    vector<int> vtmp(m, false);
    map.resize(n, vtmp);

    int tmp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) n_togo.push(make_pair(i, j));
            else if(map[i][j] == 0) cnt++;
        }
    }

    bfs();
    
    if(cnt != 0) cout << -1;
    else cout << ans;
}