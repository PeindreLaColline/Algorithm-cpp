/*14:26*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<bool> visited;

void dfs(queue<int> q){
    if(q.size() == m){
        while(!q.empty()){
            cout << q.front()<<" ";
            q.pop();
        }
        cout<<"\n";
        return;
    }

    for(int i =0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            queue<int> tmp = q;
            tmp.push(v[i]);
            dfs(tmp);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    v.resize(n);
    visited.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    queue<int> q;
    dfs(q);

}