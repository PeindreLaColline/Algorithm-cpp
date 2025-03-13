/*22:04*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 98765432

int n, m, k, x;
vector<vector<int> > road;
vector<int> dis;

void dijkstra(){
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int next;
        for(int i =0; i<road[cur].size(); i++){
            next = road[cur][i];
            if(dis[next] > dis[cur]+1){
                dis[next] = dis[cur]+1;
                q.push(next);
            }
        }
    }
}

int main(){
    cin>>n>>m>>k>>x;
    road.resize(n+1);
    dis.resize(n+1, MAX);

    int a, b;
    for(int i =0; i<m; i++){
        cin>>a>>b;
        road[a].push_back(b);
    }

    dijkstra();

    bool done = false;
    for(int i =1; i<=n; i++){
        if(dis[i]==k){
            cout<<i<<"\n";
            done = true;
        }
    }
    if(!done) cout<<"-1";
}