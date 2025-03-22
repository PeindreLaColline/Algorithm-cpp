/*13:30*/
#include <iostream>
#include <vector>
using namespace std;

#define LIMIT 1000000

int m, n;
vector<bool> visited(LIMIT+1, false);

/*
2부터 LIMIT까지 순회하는데 아직 방문처리 안 된 수는 소수로 판단
그 수를 가지고 LIMIT까지 순회하며 그 수의 모든 배수를 방문처리 함
예를 들어 2를 제외한 2의 배수는 전부 방문처리 (4, 6, 8, ...)
*/
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

    /*
    visited 배열 순회하면서 visited[i] == false 인 것만 출력 (i는 m과 n 사이)
    이때 m이 1이면 하나 증가해서 2부터 조회하는데 이는 1이 소수가 아니기 때문
    */
    if(m==1) m++;
    for(int i =m; i<=n; i++){
        if(visited[i]) continue;
        cout << i << "\n";
    }
}
