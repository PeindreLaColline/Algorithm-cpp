/*12:57*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string s;
    set<string> set;

    for(int i =0; i<n; i++){
        cin >> s;
        set.insert(s);
    }

    struct compare{
        bool operator()(const string &a, const string &b){
            return a > b;
        }
    };
    priority_queue<string, vector<string>, compare > pq;

    for(int i =0; i<m; i++){
        cin >> s;
        if(set.find(s) != set.end()){
            pq.push(s);
        }
    }

    cout << pq.size() <<"\n";
    while(!pq.empty()){
        cout << pq.top() <<"\n";
        pq.pop();
    }
}
