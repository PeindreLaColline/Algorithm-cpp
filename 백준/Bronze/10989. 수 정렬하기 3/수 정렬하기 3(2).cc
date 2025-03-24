/*14:12*/
/*
정렬해서 풀면 메모리 초과남
조금 비효율적이게 해야하는데 왜 그러냐면 메모리는 작게 주고 시간을 한 바가지 주기 때문
C++ 채점 이렇게 오래 걸리는 거 처음 봄
  */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(10001, 0);
    int tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        v[tmp]++;
    }
    for(int i =1; i<=10000; i++){
        for(int j = 0; j<v[i]; j++){
            cout << i << "\n";
        }
    }
}

// struct compare{
//     bool operator()(const int &a, const int &b){
//         return a>b;
//     }
// };

// int main(){
//     int n;
//     cin >> n;
//     priority_queue<int, vector<int>, compare > pq;
//     int tmp;
//     for(int i =0; i<n; i++){
//         cin >> tmp;
//         pq.push(tmp);
//     }
//     while(!pq.empty()){
//         cout << pq.top()<<"\n";
//         pq.pop();
//     }

// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i =0; i<n; i++){
//         cin >> v[i];
//     }
//     sort(v.begin(), v.end());

//     for(int i =0; i<n; i++){
//         cout << v[i] << "\n";
//     }
// }
