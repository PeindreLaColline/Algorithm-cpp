#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k;

int main(){
    cin >> n >> k;

    vector<int> v(100001, 98765432);
    deque<int> dq;

    v[n] = 0;
    dq.push_front(n);

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();

        if(cur * 2 <= 100000 && v[cur*2] > v[cur]){
            v[cur*2] = v[cur];
            dq.push_front(cur*2);
        }

        if(cur - 1 >= 0 && v[cur-1] > v[cur]+1){
            v[cur-1] = v[cur]+1;
            dq.push_back(cur-1);
        }

        if(cur + 1 <= 100000 && v[cur+1] > v[cur]+1){
            v[cur+1] = v[cur]+1;
            dq.push_back(cur+1);
        }

    }

    cout << v[k];
}