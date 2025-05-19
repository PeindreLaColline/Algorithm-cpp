/*10:33*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> num;
vector<char> cal;

int main(){
    string s;
    cin >> s;

  //숫자랑 연산자를 나눠서 저장
    int tmp = 0;
    for(int i =0; i<s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            tmp *= 10;
            tmp+=(s[i]-'0');
        }
        else{
            num.push_back(tmp);
            tmp = 0;
            cal.push_back(s[i]);
        }
    }
    num.push_back(tmp);

  /*
  -가 한 번 나온 이후에는 모든 수를 음수로 만들 수 있음
  그래서 첫 숫자부터 -나오기 하나 전 까지는 모두 양수로, 나머지는 음수로 저장해서
  positive - negative 출력
    */
    int positive = num[0];
    int negative = 0;
    bool minus = false;
    for(int i =0; i<cal.size(); i++){
        if(minus){
            negative += num[i+1];
        }
        else{
            if(cal[i] == '+'){
                positive += num[i+1];
            }
            else{
                negative += num[i+1];
                minus = true;
            }
        }
        
    }

    cout << positive - negative;
}
