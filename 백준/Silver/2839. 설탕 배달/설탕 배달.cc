//16:32
#include <iostream>
#include <vector>
using namespace std;

int n, ans;

int main(){
    cin >> n;
    ans = 0;
    bool done = false;
    while(n>=0){
        if(n%5 == 0){
            ans += n/5;
            done = true;
            break;
        }
        n-=3;
        ans += 1;
    }
    if(done) cout << ans;
    else cout << -1;
    
}