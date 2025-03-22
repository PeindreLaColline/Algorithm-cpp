/*13:56*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> v;
int maxi= -1000000000;
int mini= 1000000000;

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