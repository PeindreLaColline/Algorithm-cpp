/*15:42*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v;
vector<vector<pair<int, int> > > map;
int s, e;

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

void dij(){

    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        pq.pop();

        int cur = tmp.first;
        if(v[cur] != tmp.second) continue;

        for(int i =0; i<map[cur].size(); i++){
            int nex = map[cur][i].first;
            int wei = map[cur][i].second;

            if(v[nex] > v[cur] + wei){
                v[nex] = v[cur] + wei;
                pq.push(make_pair(nex, v[nex]));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(n+1, 987654321);
    map.resize(n+1, vector<pair<int, int> >(0));

    int a, b, c;
    for(int i =0; i<m; i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }

    cin >> s >> e;
    v[s] = 0;
    pq.push(make_pair(s, 0));

    dij();

    cout << v[e];

}