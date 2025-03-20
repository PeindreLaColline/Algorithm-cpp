#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;

    int num, tmp;
    for(int i = 1; i<=n; i++){
        num = i;
        tmp = i;
        while(num != 0){
            tmp += (num%10);
            num/=10; 
        }
        if(tmp == n){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;

}