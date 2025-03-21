/*00:46*/
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define LIMIT 100000

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

int n, k;
vector<int> v(LIMIT+1, 98765432);
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

void print_all(){
    for(int i =0; i<=34; i++){
        cout<<v[i]<<" ";
    }
    cout<<"size: "<<pq.size()<<endl;
}

void bfs(){
    while(!pq.empty()){
        int idx = pq.top().first;
        pq.pop();
        
        if(idx+1 <= LIMIT){
            if(v[idx]+1 < v[idx+1]){
                v[idx+1] = v[idx]+1;
                if(v[idx+1] < v[k]){
                    pq.push(make_pair(idx+1, v[idx+1]));
                }
            }
        }
        if(idx-1 >= 0){
            if(v[idx]+1 < v[idx-1]){
                v[idx-1] = v[idx]+1;
                if(v[idx-1] < v[k]){
                    pq.push(make_pair(idx-1, v[idx-1]));
                }
            }
        }
        if(idx*2 <= LIMIT){
            if(v[idx]+1 < v[idx*2]){
                v[idx*2] = v[idx]+1;
                if(v[idx*2] < v[k]){
                    pq.push(make_pair(idx*2, v[idx*2]));
                } 
            }
        }
        //print_all();
    }

}

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