//14:49
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 98765432

int n;
int a, b;
vector<int> dist(100001, INF);
vector<int> cnt(100001, 0);

void bfs(){

    queue<int> togo;

    togo.push(a);
    while(!togo.empty()){
        int cur = togo.front();
        togo.pop();

        vector<int> next = {cur-1, cur+1, cur*2};

        for(int i =0; i<3; i++){
            if(next[i] < 0 || next[i] > 100000) continue;

            if(dist[next[i]] == INF){
                dist[next[i]] = dist[cur] + 1;
                cnt[next[i]] = cnt[cur];
                togo.push(next[i]);
            }
            else if(dist[next[i]] == dist[cur]+1){
                cnt[next[i]] += cnt[cur];
            }
        }

    }
}

int main(){
    cin >> a >> b;

    dist[a] = 0;
    cnt[a] = 1;

    bfs();
    cout << dist[b] << endl;
    cout << cnt[b];

}