/*01:35*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a>b) swap(a, b);

    //1
    int ans1 = 1;
    vector<bool> v1(b+1, false);
    for(int i =1; i<=a; i++){
        if(a%i == 0) v1[i] = true;
    }
    for(int i =1; i<=b; i++){
        if(b%i == 0 && v1[i] && ans1 < i){
            ans1 = i;
        }
    }

    //2
    int ans2 = a*b;
    vector<bool> v2(a*b+1, false);
    int i = 1;
    while(i<b){
        v2[i*a] = true;
        i++;
    }
    i = 1;
    while(i<a){
        if(v2[i*b]) {
            ans2 = i*b;
            break;
        }
        i++;
    }

    //answer
    cout<<ans1<<endl;
    cout<<ans2;
}