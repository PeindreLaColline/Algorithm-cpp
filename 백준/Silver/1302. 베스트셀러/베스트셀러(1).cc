/*18:40*/
/*
들어오는 책 제목이랑 들어온 횟수 map에 저장
입력 끝나면 map 전체 순회하면서 책 제목이랑 들어온 횟수 pq에 저장
pq 제일 첫 번째거 출력
*/
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
