/*20:36*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int test;

int main(){
    cin >> test;
    for(int t = 0; t<test; t++){

        //input
        string command;
        cin >> command;

        int n;
        cin >> n;

        string tmp;
        cin >> tmp;
        
        string num;
        deque<int> dq;
        for(int i =0; i<tmp.size(); i++){
            if(isdigit(tmp[i])){
                num += tmp[i];
            }
            else{
                if(!num.empty()){
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }

        if(!num.empty()){
            dq.push_back(stoi(num));
        }

        //operate
        bool front = true;
        bool error = false;
        for(int i =0; i<command.size(); i++){
            if(command[i] == 'R'){
                front = !front;
            }
            else{
                if(!dq.empty()){
                    if(front){
                        dq.pop_front();
                    }
                    else{
                        dq.pop_back();
                    }
                }
                else{
                    error = true;
                    break;
                }
            }
        }

        //output
        if(error){
            cout << "error" << "\n";
            continue;
        }
        else{
            cout <<"[";
            if(!dq.empty()){
                if(front){
                    while(true){
                        cout<<dq.front();
                        dq.pop_front();
                        if(!dq.empty()) cout << ",";
                        else break;
                    }
                }
                else{
                    while(true){
                        cout<<dq.back();
                        dq.pop_back();
                        if(!dq.empty()) cout << ",";
                        else break;
                    }
                }
                
            }
            cout << "]" <<"\n";
            
        }
    }
}