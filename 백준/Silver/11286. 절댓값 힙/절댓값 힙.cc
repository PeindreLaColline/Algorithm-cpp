/*00:14*/
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct compare{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) return a.second > b.second;
        else return a.first > b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int tmp;

    for(int i =0; i<n; i++){
        cin >> tmp;
        if(tmp != 0) pq.push(make_pair(abs(tmp), tmp));
        else{
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
    }

    return 0;


}