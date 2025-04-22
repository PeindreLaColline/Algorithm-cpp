/*18:40*/
#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

struct compare{
    bool operator()(const pair<string, int> &a, const pair<string, int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        else{
            return a.second < b.second;
        }
    }
};
int n;
map<string, int> book;
priority_queue<pair<string, int>, vector<pair<string, int> >, compare> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    string tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        if(book.find(tmp) != book.end()){
            book[tmp]++;
        }
        else{
            book[tmp] = 1;
        }
    }

    for(auto it : book){
        pq.push(make_pair(it.first, it.second));
    }

    cout << pq.top().first;
}