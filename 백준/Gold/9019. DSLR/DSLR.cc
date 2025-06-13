/*11:12*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> v;
vector<bool> visited;

queue<int> togo;
queue<int> n_togo;
queue<int> emp;

int a, b;

int func_d(int num){
    return (num * 2) % 10000;
}

int func_s(int num){
    if(num == 0) return 9999;
    else return num-1;
}

int func_l(int num){
    int d1 = (num / 1000) % 10;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = (num) % 10;

    return (d2*1000) + (d3*100) + (d4*10) + d1;
}

int func_r(int num){
    int d1 = (num / 1000) % 10;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = (num) % 10;

    return (d4*1000) + (d1*100) + (d2*10) + d3;
}

void bfs(){
    while(!n_togo.empty()){
        togo = n_togo;
        n_togo = emp;

        while(!togo.empty()){
            if(v[b].size() != 0) return;
            int num = togo.front();
            togo.pop();
            
            int tmp = func_d(num);
            if(!visited[tmp]){
                visited[tmp] = true;
                v[tmp] = v[num] + "D";
                n_togo.push(tmp);
            }

            tmp = func_s(num);
            if(!visited[tmp]){
                visited[tmp] = true;
                v[tmp] = v[num] + "S";
                n_togo.push(tmp);
            }

            tmp = func_l(num);
            if(!visited[tmp]){
                visited[tmp] = true;
                v[tmp] = v[num] + "L";
                n_togo.push(tmp);
            }

            tmp = func_r(num);
            if(!visited[tmp]){
                visited[tmp] = true;
                v[tmp] = v[num] + "R";
                n_togo.push(tmp);
            }

        }
    }
}
int main(){
    int test;
    cin >> test;

    for(int t = 0; t<test; t++){

        v.clear();
        v.resize(10000, string());

        visited.clear();
        visited.resize(10000, false);

        togo = emp;
        n_togo = emp;

        cin >> a >> b;

        visited[a] = true;
        n_togo.push(a);

        bfs();

        cout << v[b] << '\n';

    }
}