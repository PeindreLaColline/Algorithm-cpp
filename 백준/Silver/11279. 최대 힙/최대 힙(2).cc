/*11:09*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, less< > > pq;

    int num;
    for(int i =0; i<n; i++){
        cin >> num;
        if(num == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }
}
