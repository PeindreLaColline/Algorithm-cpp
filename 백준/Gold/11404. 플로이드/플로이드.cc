#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct po{
    int a;
    int b;
    int val;
    po(int _a, int _b, int _val) : a(_a), b(_b), val(_val) {}
};

struct compare{
    bool operator()(const po &a, const po &b){
        return a.val < b.val;
    }
};

int n, m;
vector<vector<int> > map;

priority_queue<po, vector<po>, compare> pq;

void floid(){
    while(!pq.empty()){
        int ca = pq.top().a;
        int cb = pq.top().b;
        int cval = pq.top().val;
        pq.pop();

        if(map[ca][cb] != cval) continue;

        for(int i=1; i<=n; i++){
            if(ca == i || cb == i) continue;

            if(map[ca][i] > map[ca][cb] + map[cb][i]){
                map[ca][i] = map[ca][cb] + map[cb][i];
                pq.push(po(ca, i, map[ca][i]));
            }

            if(map[i][cb] > map[i][ca] + map[ca][cb]){
                map[i][cb] = map[i][ca] + map[ca][cb];
                pq.push(po(i, cb, map[i][cb]));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    map.resize(n+1, vector<int>(n+1, 987654321));

    int a, b, val;
    for(int i =0; i<m; i++){
        cin >> a >> b >> val;
        if(map[a][b] > val){
            map[a][b] = val;
            pq.push(po(a, b, map[a][b]));
        }
    }

    for(int i =1; i<=n; i++){
        map[i][i] = 0;
    }

    floid();

    for(int i =1; i<=n; i++){
        for(int j =1; j<=n; j++){
            if(map[i][j] == 987654321) cout << 0 << " ";
            else cout << map[i][j] <<" ";
        }
        cout <<'\n';
    }

}