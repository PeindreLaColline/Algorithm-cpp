//17:37
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

struct compare{
    bool operator()(const int &a, const int &b){
        return a>b;
    }
};
priority_queue<int, vector<int>, compare> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        if(tmp > 0){
            pq.push(tmp);
        }
        else if(tmp == 0){
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }

    }
}