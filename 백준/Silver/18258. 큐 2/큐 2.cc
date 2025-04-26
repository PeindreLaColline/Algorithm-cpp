/*16:09*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int n;
deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string s;
    int num;
    for(int i =0; i<n; i++){
        cin >> s;

        if(s == "push"){
            cin >> num;
            dq.push_back(num);
        }
        else if(s == "pop"){
            if(dq.empty()){
                cout << -1 <<"\n";
            }
            else{
                cout << dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else if(s == "size"){
            cout << dq.size()<<"\n";
        }
        else if(s == "empty"){
            cout << dq.empty() <<"\n";
        }
        else if(s == "front"){
            if(dq.empty()){
                cout << -1 <<"\n";
            }
            else{
                cout << dq.front() <<"\n";
            }
        }
        else{
            if(dq.empty()){
                cout << -1 <<"\n";
            }
            else{
                cout << dq.back() <<"\n";
            }
        }
    }
}