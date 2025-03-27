/*15:40*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    string line;
    
    cin >> n;
    while(n>0){

        cin >> line;
        stack<bool> s;

        bool done = true;
        for(int i =0; i<line.size(); i++){
            if(line[i] == '('){
                s.push(true);
            }
            else{
                if(!s.empty()){
                    s.pop();
                }
                else{
                    done = false;
                    break;
                }
            }
        }

        if(done && s.empty()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }


        n--;
    }
}