/*14:29*/
/*
일단 모든 입력을 다 받음 사실 옷의 이름은 상관이 없음 어차피 중복 없이 들어와서
(옷 이름, 옷 종류) 이렇게 입력받아서 배열에 저장
그리고는 옷 종류를 기준으로 정렬함
이 배열을 순회하면서 새로운 옷 종류가 나올 때마다 clothes배열 사이즈 하나 늘림
이때 clothes배열은 옷 종류당 몇개의 옷이 있는지 카운팅하는 배열

이제 (clothes[i]+1) 을 다 곱하고 1을 빼줌 (중복허용되는 수열인데 옷이 아무것도 없으면 안 되니까 1 뺌) 이거 출력하는 게 정답
근데 n이 0일 때는 가능한 경우의 수가 없으므로 0출력하고 해당 테케 종료

이렇게 풀긴했지만 set을 쓰면 훨씬 간편한 코드가 되었을 듯 합니다 저는 쓸 줄 몰라서 일단 막무가내로 풀었습니다
    */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int test_case;
int n;
vector<pair<string, string> > v;
vector<int> clothes;

bool compare(const pair<string, string> &a, const pair<string, string> &b){
    return a.second>b.second;
}

int main(){
    cin >> test_case;
    for(int t = 0; t<test_case; t++){
        cin >> n;
        if(n==0){
            cout << 0 << endl;
            continue;
        }
        
        v.clear();
        v.resize(n);
        clothes.clear();
        clothes.resize(1, 0);

        for(int i =0; i<n; i++){
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), compare);

        string tmp = v[0].second;
        int idx = 0;
        clothes[idx]++;
        for(int i =1; i<n; i++){
            if(tmp == v[i].second){
                clothes[idx]++;
            }
            else{
                clothes.push_back(0);
                idx++;
                clothes[idx]++;
                tmp = v[i].second;
            }
        }

        int ans = 1;
        for(int i =0; i<clothes.size(); i++){
            ans *= (clothes[i]+1);
        }
        cout << --ans << endl;

    }
}
