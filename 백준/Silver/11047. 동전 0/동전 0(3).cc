/*01:44*/
/*
동전 제일 큰 거를 제일 많이 넣어보고, 남은 건 하나 작은 동전으로 끝까지 채워보고.. 반복하다가 끝까지 갔는데도 안 되면 개수를 줄이고 이런 식으로 브루트포스
브루트포스하는 중에도 계속 cnt랑 ans이랑 값 비교해보고 유망하지 않다고 판단되면 바로 return해야지 시간초과 안 남
    */
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

int ans = 987654321;
void dfs(int idx, int val, int cnt){
    if(val == 0){
        ans = min(ans, cnt);
        return;
    }
    else if(val < 0 ) return;
    if(idx < 0) return;
    if(cnt > ans) return;

    for(int i = val/v[idx]; i>=0; i--){
        if(cnt+i > ans) return;
        dfs(idx-1, val-v[idx]*i, cnt+i);
    }
}

int main(){
    cin >> n >> k;

    v.resize(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    dfs(n-1, k, 0);

    cout << ans;



}
