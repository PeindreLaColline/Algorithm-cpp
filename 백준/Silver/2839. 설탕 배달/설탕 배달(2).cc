/*이거 여러번 풀었는데 그리디가 머리 안 아프고 젤 편한 것 같아요..*/
#include <iostream>
using namespace std;

int main(){
    int num;
    int ans = 0;
    bool done = false;
    cin >> num;
    
    while(num >= 0){
        if(num % 5 == 0){
            ans += num / 5;
            done = true;
            break;
        }
        num -= 3;
        ans++;
    }
    
    if(done) cout << ans << endl;
    else cout << -1 << endl;
}
