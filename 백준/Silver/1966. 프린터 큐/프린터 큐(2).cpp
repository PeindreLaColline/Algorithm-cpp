/*
pq에는 우선순위 넣음 -> 지금 q안에 있는 우선순위 중에 가장 큰게 뭔지 알기위해서
q에는 들어오는 순서대로 (순서, 우선순위)를 튜플로 넣음
q의 가장 앞에 있는 요소의 우선순위가 현재 q에서 가장 큰 우선순위면 pop
이때 이게 가장 큰 우선순위인지 아는 방법은 pq의 가장 앞에 거를 확인하면 됨
*/
#include <iostream>
#include <queue>
using namespace std;

int test_case;
int n, m;

int main(){
    cin >> test_case;

    for(int t = 0; t<test_case; t++){
        queue<pair<int, int> > q;
        priority_queue<int> pq; 
        cin >> n >> m;
        
        int tmp;
        for(int i =0; i<n; i++){
            cin >> tmp;
            pq.push(tmp);
            q.push(make_pair(i, tmp));
        }

        int cnt = 1;
        while(true){
            if(q.front().second == pq.top()){
                if(q.front().first == m){
                    cout << cnt << endl;
                    break;
                }
                q.pop();
                pq.pop();
                cnt++;
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
    }
}
