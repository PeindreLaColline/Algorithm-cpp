#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num(9);
vector<bool> visited(9);
vector<bool> ans(9);

void greedy(int s, int sum, int cnt){
    if (cnt == 7){
        if(sum == 100){
            ans = visited;
        }
        return;
    }
    if(sum > 100) return;
    for(int i =s; i<9; i++){
        if(visited[i] == false){
            visited[i] = true;
            greedy(i, sum+num[i], cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    for(int i =0; i<9; i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end());
    greedy(0, 0, 0);
    for(int i =0; i<9; i++){
        if(ans[i] == true){
            cout<<num[i]<<"\n";
        }
    }
}