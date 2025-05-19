/*11:08*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;

    int tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(tmp);
        }
    }
}
