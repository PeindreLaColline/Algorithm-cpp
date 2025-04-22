/*02:46*/
/*입력된 문자열에서 슬라이딩윈도우 방식으로 부분문자열을 뽑음
뽑힌 부분문자열 set에 저장
set 사이즈 출력하면 부분문자열 개수*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

string s;
set<string> ss;

void get_ss(int leng){
    for(int i =0; i<=s.size()-leng; i++){
        ss.insert(s.substr(i, leng));
    }
}

int main(){
    cin >> s;
    for(int i =1; i<=s.size(); i++){
        get_ss(i);
    }

    // for(auto it:ss){
    //     cout << it<<endl;
    // }
    cout << ss.size();
}