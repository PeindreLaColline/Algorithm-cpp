#include <string>
#include <vector>
using namespace std;

int answer = 0;
int n, target;
vector<int> numbers;

void dfs(int ind, int sum){
    if(ind == n){
        if(sum == target) answer++;
        return;
    }
    
    dfs(ind+1, sum+numbers[ind]);
    dfs(ind+1, sum+(-1)*numbers[ind]);
}

int solution(vector<int> tnum, int t) {
    
    numbers = tnum;
    target = t;
    n = numbers.size();
    
    dfs(1, numbers[0]);
    dfs(1, (-1)*numbers[0]);
    
    return answer;
}