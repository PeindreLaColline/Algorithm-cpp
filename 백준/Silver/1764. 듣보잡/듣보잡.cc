/*10:19*/
/*
set 활용
듣도못한 사람 이름 전부 set에 저장
보도못한 사람 이름 들어올 때마다 set에서 조회해서 이미 존재하는 이름이면 pq에 저장
pq 사이즈 및 저장된 이름 출력
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

struct compare{
    bool operator()(string const &a, string const &b){
        return a > b;
    }
};

int n, m;
set<string> s;
priority_queue<string, vector<string>, compare> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    string tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        s.insert(tmp);
    }

    for(int i =0; i<m; i++){
        cin >> tmp;
        if(s.find(tmp) != s.end()){
            pq.push(tmp);
            s.erase(tmp);
        }
    }

    cout << pq.size()<< endl;
    while(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }


}