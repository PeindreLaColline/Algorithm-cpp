#include <iostream>
using namespace std;

unsigned int n = 1;
unsigned int s;

int main(){
    cin>>s;
    if(s==2){
        cout<<1;
    }
    else{
        unsigned int i = 0;
        while(true){
            if(i>=s) {
                n--;
                break;
            }
            i++;
            s-=i;
            n++;
        }
        cout<<n;
    }
}