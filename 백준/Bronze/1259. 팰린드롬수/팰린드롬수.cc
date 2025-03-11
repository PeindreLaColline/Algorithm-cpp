#include <iostream>
#include <string>
using namespace std;

int main(){
    string tmp;
    int leng;
    bool pal;

    while(true){
        cin >> tmp;
        leng = tmp.size();
        pal = true;

        if(tmp == "0") break;
        
        for(int i =0; i<leng/2; i++){
            if(tmp[i] != tmp[leng-1-i]){
                pal = false;
                break;
            }
        }
        if(pal) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}