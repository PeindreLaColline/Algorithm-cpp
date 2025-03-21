/*00:46*/
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define LIMIT 100000

//변수 선언
struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

int n, k;
vector<int> v(LIMIT+1, 98765432);
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

//bfs라고 풀었는데 지피티가 다익스트라라고 하더라 흠
void bfs(){
    while(!pq.empty()){
        int idx = pq.top().first;
        pq.pop();
        
        if(idx+1 <= LIMIT){ //x+1로 움직임
            if(v[idx]+1 < v[idx+1]){
                v[idx+1] = v[idx]+1;
                if(v[idx+1] < v[k]){
                    pq.push(make_pair(idx+1, v[idx+1]));
                }
            }
        }
        if(idx-1 >= 0){ //x-1로 움직임
            if(v[idx]+1 < v[idx-1]){
                v[idx-1] = v[idx]+1;
                if(v[idx-1] < v[k]){
                    pq.push(make_pair(idx-1, v[idx-1]));
                }
            }
        }
        if(idx*2 <= LIMIT){ //x*2로 움직임
            if(v[idx]+1 < v[idx*2]){
                v[idx*2] = v[idx]+1;
                if(v[idx*2] < v[k]){
                    pq.push(make_pair(idx*2, v[idx*2]));
                } 
            }
        }
    }

}

/*처음에는 순간이동없이 걷기만 했을 때 걸리는 시간으로 배열을 초기화하고 시작했는데 이러면 안 됐음
어쨌든 모든 경우의 수를 따져야하는 건데 내가 원래 했던 방식으로 하면 모든 인덱스를 방문할 수 없는 구조이기 때문
배열값을 987654321로 초기화해줘서 해결
*/
int main(){
    cin >> n >> k;
    // for(int i =0; i<=LIMIT; i++){
    //     v[i] = abs(n-i);
    // }
    v[n] = 0;
    pq.push(make_pair(n, v[n]));

    bfs();
    cout<<v[k];
}
