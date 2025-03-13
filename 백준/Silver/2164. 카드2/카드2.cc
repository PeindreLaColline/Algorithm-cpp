/*14:37*/
#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main(){
    cin >> n;
    for(int i =1; i<=n; i++){
        q.push(i);
    }

    while(q.size() != 1){
        if(!q.empty()){
            q.pop();
        }
        if(!q.empty()){
            q.push(q.front());
            q.pop();
        }
    }

    cout << q.front();
}