/*00:28*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int> > map;
vector<bool> visited;

void dfs(int s){
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i<n; i++){
            if(map[cur][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
                map[s][i] = 1;
            }
        }

    }
}

int main(){
    cin >> n;
    map.resize(n, vector<int>(n));

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> map[i][j];
        }
    }

    for(int i =0; i<n; i++){
        visited.clear();
        visited.resize(n, false);
        dfs(i);
    }

    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}