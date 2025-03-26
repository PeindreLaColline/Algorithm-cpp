/*23:22*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(){
    string line;
    while(true){
        stack<int> s;
        bool done = true;

        getline(cin, line);
        if(line==".") break;

        for(int i =0; i<line.size(); i++){
            if(line[i] == '('){
                s.push(1);
            }
            else if(line[i] == ')'){
                if(!s.empty() && s.top() == 1){
                    s.pop();
                    continue;
                }
                else{
                    done = false;
                    break;
                }
                
            }
            else if(line[i] == '['){
                s.push(2);
            }
            else if(line[i] == ']'){
                if(!s.empty() && s.top() == 2) {
                    s.pop();
                    continue;
                }
                else{
                    done = false;
                    break;
                }
            }
        }

        if(done && s.empty()) cout << "yes\n";
        else cout << "no\n";  

    }

}