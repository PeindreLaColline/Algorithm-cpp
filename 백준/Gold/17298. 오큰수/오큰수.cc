/*12:31*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> v;
vector<int> ans;

stack<int> s;

int main(){
    cin >> n;
    v.resize(n);
    ans.resize(n, -1);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    for(int i = n-1; i>=0; i--){
        while(!s.empty() && s.top() <= v[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = s.top();
        }
        s.push(v[i]);
    }

    for(int i =0; i<n; i++){
        cout << ans[i] <<" ";
    }
}
/*
10
18 10 2 16 13 11 15 4 1 5
*/