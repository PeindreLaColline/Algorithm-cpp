/*11:52*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int tmp = 0;
    bool even;
    for(int i =0; i<13; i++){
        if(s[i] == '*'){
            if(i%2 == 0) even = true;
            else even = false;
            continue;
        }

        if(i%2 == 0) tmp += (s[i]-'0');
        else tmp += ((s[i]-'0')*3);
    }
    
    if(!even){
        for(int i =0; i<=9; i++){
            if((tmp + (i * 3)) % 10 == 0){
                cout << i;
                break;
            }
        }
    }
    else cout << 10 - (tmp%10);
    
}