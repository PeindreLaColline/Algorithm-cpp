/*13:30*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define LIMIT 1000000

int m, n;
vector<bool> visited(LIMIT+1, false);

void prime(){
    for(int i =2; i<=n; i++){
        if(visited[i]) continue;
        int num = 2;
        while(i*num <= n){
            visited[i*num] = true;
            num++;
        }
    }
}

int main(){
    cin >> m >> n; // m <= n
    prime();
    if(m==1) m++;
    for(int i =m; i<=n; i++){
        if(visited[i]) continue;
        cout << i << "\n";
    }
}

// struct compare{
//     bool operator()(const int &a, const int &b){
//         return a < b;
//     }
// };

// int m, n;
// priority_queue<int, vector<int>, compare> pq;
// vector<bool> visited(LIMIT+1, false);

// void prime(){
//     while(!pq.empty()){
//         int num = pq.top();

//         while(num<=LIMIT){
            
//         }
//     }
    
// }

// int main(){
//     cin >> n >> m;
//     for(int i =1; i<= LIMIT; i++){
//         pq.push(i);
//     }
// }