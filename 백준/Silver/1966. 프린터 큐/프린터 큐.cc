/*16:45*/
/*
문제에서 설명한 그대로 구현했어요
뒤에 나보다 큰 우선순위 있으면 큐 제일 뒤로 보내고
내가 지금 제일 큰 우선순위면 출력하고 지우고
말고 더 똑똑한 생각이 안 나더라구
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int test_case;
int n, m;
vector<int> v;

int main(){
    cin >> test_case;
    for(int t = 0; t<test_case; t++){
        
        cin >> n >> m;
        int priority;
        queue<pair<int, int> > q;
        v.clear();
        v.resize(10, 0);
        for(int i =0; i<n; i++){
            cin >> priority;
            v[priority]++;
            q.push(make_pair(i, priority));
        }
        
        priority = 9;
        int cnt = 1;
        while(priority!=0){
            if(v[priority]==0){
                priority--;
                continue;
            }
            
            if(q.front().second == priority){   
                if(q.front().first == m){
                    cout<<cnt<<endl;
                    break;
                }
                v[priority]--;
                q.pop();
                cnt++;
                continue;
            } 
            else{
                q.push(q.front());
                q.pop();
            }           
        }
    }
}