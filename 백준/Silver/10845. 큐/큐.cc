/*16:01*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n;
vector<string> v;
deque<int> dq;

int main(){
    cin >> n;
    v.resize(n);
    string s;
    int tmp;
    for(int i =0; i<n; i++){
        cin >> s;
        if(s == "push"){
            cin>> tmp;
            dq.push_back(tmp);
        }
        else if(s == "pop"){
            if(!dq.empty()){
                cout << dq.front()<<"\n";
                dq.pop_front();
            }
            else{
                cout << "-1" << "\n";
            }
        }
        else if(s == "size"){
            cout << dq.size() << "\n";
        }
        else if(s == "empty"){
            cout << dq.empty() << "\n";
        }
        else if(s == "front"){
            if(!dq.empty()){
                cout << dq.front()<<"\n";
            }
            else{
                cout << "-1" << "\n";
            }
        }
        else if(s == "back"){
            if(!dq.empty()){
                cout << dq.back()<<"\n";
            }
            else{
                cout << "-1" << "\n";
            }
        }
    }
}