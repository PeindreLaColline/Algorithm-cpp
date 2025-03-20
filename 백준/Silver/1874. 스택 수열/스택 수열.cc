/*00:59*/
/*
전략
1-n까지의 수열을 섞는다고 생각하지말고 주어진 주열을 순서대로 정렬한다는 접근이 간단함
예제: 4 3 6 8 7 5 2 1
스택에서 가장 늦게 나온 순서대로 하나씩 읽어나가며 정렬함 (이 예시에서는 1이 가장 늦게 나온 숫자)
목표는 n-1까지 역순으로 정렬하는 것
*/
/*
순서
1 2 5 7 8 까지 스택에 넣는다 (- - - - -)
8이 최대값이니 빼준다 (+)
7이 그 다음 최댓값이니 빼준다 (+)
스택에 들어간 숫자는 1 2 5, 봐야할 나머지 숫자들은 4 3 6
6이 그다음 최댓값이니 스택에 넣었다가 빼준다(- +)
5가 그다음 최댓값이니 스택에서 빼준다 (+)
...의 순서로 진행을 하면 나머지는 
(- - + + + +)이 나옵니다
*/
#include <iostream>
#include <stack>
using namespace std;

int n;
int maxi;
stack<int> s1;
stack<int> s2;
stack<char> ans;

int main(){
    cin >> n;
    int tmp;
    for(int i =0; i<n; i++){
        cin >> tmp;
        s1.push(tmp);
    }

    maxi = n;

    while(maxi >= 1){
        if(s1.empty() && s2.empty()){
            ans.push('.');
            break;
        }
        if(!s2.empty() && s2.top() == maxi){
            maxi--;
            ans.push('+');
            s2.pop();
            continue;
        }
        if(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            ans.push('-');
        }
        else{
            ans.push('.');
            break;
        }
        
    }

    if(ans.top() == '.'){
        cout << "NO";
    }
    else{
        while(!ans.empty()){
            cout<<ans.top()<<"\n";
            ans.pop();
        }
    }
}