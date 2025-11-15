//16:07
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

#define INF 1e9

int n, e;
int v1, v2;
vector<vector<int> > map;
vector<int> dist;

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

void get_dist(int start){
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> togo;
    dist[start] = 0;
    togo.push(make_pair(start, 0));

    while(!togo.empty()){
        int cur = togo.top().first;
        int val = togo.top().second;
        togo.pop();

        if(val > dist[cur]) continue;

        for(int i =1; i<=n; i++){
            if(i == cur) continue;
            int next = i;
            int n_val = val+map[cur][next];
            
            if(dist[next] > n_val){
                dist[next] = n_val;
                togo.push(make_pair(next, n_val));
            }
        }

    }
}

int main(){
    cin >> n >> e;

    map.resize(n+1, vector<int>(n+1, INF));

    int a, b, c;

    for(int i = 0; i<e; i++){
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
    }

    cin >> v1 >> v2;

    dist.clear();
    dist.resize(n+1, INF);
    get_dist(1);
    int sv1 = dist[v1];
    int sv2 = dist[v2];

    dist.clear();
    dist.resize(n+1, INF);
    get_dist(v1);
    int v1v2 = dist[v2];

    dist.clear();
    dist.resize(n+1, INF);
    get_dist(n);
    int v1e = dist[v1];
    int v2e = dist[v2];

    int dist1 = INF;
    int dist2 = INF;

    if(sv1 < INF && v1v2 < INF && v2e < INF) dist1 = sv1 + v1v2 + v2e;
    if(sv2 < INF && v1v2 < INF && v1e < INF) dist2 = sv2 + v1v2 + v1e;

    int ans = min(dist1, dist2);
    if(ans < INF) cout << ans;
    else cout << -1;
}