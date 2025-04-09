/*16:23*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1;
    int num = 1;
    while(true){

        if(n<=num){
            cout << i;
            break;
        }
        else{
            i++;
            num += (i*6)-6;
        }
        
    }
}