/*11:00*/
/*i를 만드는 경우의 수는 i-3, i-2, i-1을 만드는 경우의 수를 모두 합한 것
예를 들어 3은 3, 12, 21, 111 이라는 조합을 가지는데
4에 대한 경우의 수를 구할 때는 3의 경우에서 끝에 1만 더해주면 됨 -> 31, 121, 211, 1111
마찬가지로 2의 경우에서 2 더해주고 3에서 3더해주고 하는 식으로
그렇기 때문에 앞에 3개 값 더한 값이 결과값
*/
#include <iostream>
#include <vector>
using namespace std;

int num;

int main(){
    int test;
    cin >> test;
    
    for(int t = 0; t<test; t++){

        cin >> num;

        vector<int> dp(num+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for(int i =4; i<=num; i++){
            dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]);
        }

        cout << dp[num] <<"\n";

    }

}
