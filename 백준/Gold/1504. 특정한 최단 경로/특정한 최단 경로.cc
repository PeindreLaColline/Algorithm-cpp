//13:40
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int n, e;
vector<vector<int> > map;
vector<int> dist;

struct compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
};

void get_distance(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    dist[start] = 0;
    pq.push(make_pair(start, 0));

    while(!pq.empty()){
        int cur = pq.top().first;
        int cost = pq.top().second;
        
        pq.pop();

        if(cost > dist[cur]) continue;

        for(int i =1; i<=n; i++){
            if(cur == i) continue;
            int next = i;
            int n_cost = cost + map[cur][next];

            if(n_cost < dist[next]){
                dist[next] = n_cost;
                pq.push(make_pair(next, n_cost));
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

    cin >> a >> b;
    
    dist.clear();
    dist.resize(n+1, INF);
    get_distance(a);
    int ab = dist[b];
    int ae = dist[n];
    
    dist.clear();
    dist.resize(n+1, INF);
    get_distance(1);
    int sa = dist[a];
    int sb = dist[b];

    dist.clear();
    dist.resize(n+1, INF);
    get_distance(b);
    int be = dist[n];

    int path1 = INF;
    int path2 = INF;

    if(sa < INF && ab < INF && be < INF) path1 = sa + ab + be;
    if(sb < INF && ab < INF && ae < INF) path2 = sb + ab + ae;

    long long ans = min(path1, path2);
    if(ans >= INF) cout << -1;
    else cout << ans;
    
}