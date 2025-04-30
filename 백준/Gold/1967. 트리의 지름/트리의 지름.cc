/*14:48*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<pair<int, int> > > map;
vector<bool> visited;

int ans = 0;
int idx = 0;

void dfs(int cur, int wei){
    bool done = false;
    for(int i =0; i<map[cur].size(); i++){
        int next = map[cur][i].first;

        if(visited[next]) continue;

        visited[next] = true;
        dfs(next, wei + map[cur][i].second);
        visited[next] = false;
        done = true;
    }

    if(!done){
        if(ans < wei){
            ans = wei;
            idx = cur;
        }
        return;
    }

}

int main(){
    cin >> n;
    map.resize(n+1, vector<pair<int, int> >(0));

    int a, b, c;
    for(int i =1; i<n; i++){
        cin >> a >> b>> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    visited.resize(n+1, false);
    visited[1] = true;
    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);
    visited[idx] = true;
    dfs(idx, 0);
    
    cout << ans;
}