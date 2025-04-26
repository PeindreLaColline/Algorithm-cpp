/*14:15*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<long long> v;
vector<int> op(4); // + - * /
long long mini = 1876543210;
long long maxi = -1876543210;

void dfs(int dep, long long cur){

    if(dep == n){
        maxi = max(maxi, cur);
        mini = min(mini, cur);
        return;
    }
    
    for(int i =0; i<4; i++){
        if(op[i] > 0){
            op[i]--;
            
            if(i==0){
                dfs(dep+1, cur + v[dep]);
            }
            else if(i==1){
                dfs(dep+1, cur - v[dep]);
            }
            else if(i==2){
                dfs(dep+1, cur * v[dep]);
            }
            else{
                dfs(dep+1, cur / v[dep]);
            }

            op[i]++;
        }
    }

}

int main(){
    cin >> n;
    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    for(int i =0; i<4; i++){
        cin >> op[i];
    }

    dfs(1, v[0]);

    cout << maxi << endl;
    cout << mini << endl;

}