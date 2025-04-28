/*14:47*/
#include <iostream>
#include <vector>
using namespace std;

int a, b;
int ans = 987654321;
void check(int cnt, long long cur){
    if(cur > b) return;
    else if(cur == b){
        ans = min(ans, cnt);
        return;
    }
    
    check(cnt+1, cur*10+1);
    check(cnt+1, cur*2);
}

int main(){
    cin >> a >> b;
    check(1, a);
    if(ans == 987654321) cout << -1;
    else cout << ans;
}