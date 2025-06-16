/*13:36*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

vector<vector<pair<int, int> > > v;
vector<bool> visited;
vector<int> dist;

pair<int, int> ans = make_pair(0, 0);

void dfs(int idx, int val){
    if(ans.second < val) ans = make_pair(idx, val);
    if(v[idx].size() == 0) return;

    for(int i =0; i<v[idx].size(); i++){
        if(visited[v[idx][i].first]) continue;

        visited[v[idx][i].first] = true;
        dfs(v[idx][i].first, val + v[idx][i].second);
        visited[v[idx][i].first] = false;

    }
}

int main(){
    
    cin >> n;

    v.resize(n+1, vector<pair<int, int> >());
    visited.resize(n+1, false);
    dist.resize(n+1, 0);

    int a, b, val;
    for(int i =0; i<n; i++){
        cin >> a;
        while(true){
            cin >> b;
            if(b == -1) break;
            cin >> val;

            v[a].push_back(make_pair(b, val));
        }
    }

    visited[1] = true;
    dfs(1, 0);

    visited.clear();
    visited.resize(n+1, false);
    visited[ans.first] = true;
    dfs(ans.first, 0);

    cout << ans.second;



}