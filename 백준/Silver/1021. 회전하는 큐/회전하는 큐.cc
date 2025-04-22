/*01:52*/
/*
수열에 배열 저장할 때 인덱스 번호는 원소, 해당 인덱스에 저장된 값은 전후로 유효한 인덱스 값임
예를 들어 123456789라는 수열이 있었는데 2345가 빠졌다면 v[1].second에 저장된 값은 6
현재 큐의 시작점이 어딘지 s에 저장함 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int> > v;

//현재 헤드인덱스에서 목표숫자까지 갈 때 왼쪽으로 돌리는게 더 빠른지, 오른쪽으로 돌리는게 더 빠른지 체크
pair<bool, int> check(int s, int num){
    int left = 0;
    int cur = s;
    while(true){
        if(cur == num) break;
        cur = v[cur].first;
        left++;
    }

    int right = 0;
    cur = s;
    while(true){
        if(cur == num) break;
        cur = v[cur].second;
        right++;
    }

    if(left<right){
        return make_pair(false, left);
    }
    else{
        return make_pair(true, right);
    }
}

int main(){
    // init
    cin >> n >> m;
    v.resize(n+1);

    // 각 요소의 앞과 뒤에 어느 인덱스가 valid한지 저장
    for(int i =1; i<=n; i++){
        v[i] = make_pair(i-1, i+1);
    }
    v[1].first = n;
    v[n].second = 1;
    int s = 1; //queue의 머리 인덱스
    


    int num;
    int ans = 0;
    for(int i =0; i<m; i++){
        cin >> num;
        pair<bool, int> p = check(s, num);

        //목표숫자 비활성화 처리
        v[v[num].first].second = v[num].second;
        v[v[num].second].first = v[num].first;

        s = v[num].second;

        v[num].first = 0;
        v[num].second = 0;

        //움직인 만큼 ans에 더해주기
        ans += p.second;

        // cout<<i<<"------------"<<endl;
        // for(int i =0; i<=n; i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }

    }

    cout << ans;

}