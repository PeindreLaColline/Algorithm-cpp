/*17:01*/
#include <iostream>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;

    int a = 1;
    int b = 1;
    int val = 1;
    int ans = 0;
    while(a<=b && b<=n){
        if(val < n){
            b++;
            val += b;
        }
        else if(val > n){
            val -= a;
            a++;
        }
        else{
            ans++;
            b++;
            val += b;
        }
        //cout<<a<<" "<<b<<" "<<val<<endl;
    }

    cout << ans;
}