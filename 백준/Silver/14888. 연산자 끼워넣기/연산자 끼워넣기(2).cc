/*13:56*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> v;
int maxi= -1000000000; //-1e9로 쓰면 double에서 int 변환과정에 오류나기 때문에 숫자 그대로 씀
int mini= 1000000000;

/*
oper에는 각 연산자마다 몇번 사용할 수 있는지가 저장 돼 있음
각 연산자의 사용 횟수가 남아있으면 그 연산자를 사용해서 계산하고 back 다시 호출해서 또 계산
반복해서 마지막 숫자까지 계산 완료하면 max min값 업데이트
*/
void back(vector<int> oper, int num, int idx){
    if(idx == n){
        mini = min(mini, num);
        maxi = max(maxi, num);
        return;
    }

    if(oper[0] > 0){
        oper[0]--;
        back(oper, num+v[idx], idx+1);
        oper[0]++;
    }
    if(oper[1] > 0){
        oper[1]--;
        back(oper, num-v[idx], idx+1);
        oper[1]++;
    }
    if(oper[2] > 0){
        oper[2]--;
        back(oper, num*v[idx], idx+1);
        oper[2]++;
    }
    if(oper[3] > 0){
        oper[3]--;
        back(oper, num/v[idx], idx+1);
        oper[3]++;
    }
}

int main(){
    cin >> n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    vector<int> oper(4); //덧셈 뺄셈 곱셈 나눗셈
    for(int i =0; i<4; i++){
        cin >> oper[i];
    }

    back(oper, v[0], 1);
    
    cout << maxi << endl;
    cout << mini << endl;
}
