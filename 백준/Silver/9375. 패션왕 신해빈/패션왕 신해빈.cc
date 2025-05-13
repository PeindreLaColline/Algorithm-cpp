/*11:55*/
/*옷이름은 안 중요하고 카테고리만 보면 되기 때문에 map에다가 해당 카테고리 옷이 몇개있는지 카운트
근데 어떤 카테고리가 있는지 우리는 모르니까 새로운 카테고리 들어올 때마다 벡터에 저장해둠 -> 맵에 뭐 있는지 순회할 때 쓰임
답 계산은 ans *= (카테고리 별 옷 가지수 + 1) 반복문 돌림
거기서 -1 (아무것도 안 고른 경우) 하면 답
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){

    int test;
    cin >> test;

    int n;
    for(int t = 0; t<test; t++){
        
        cin >> n;

        map<string, int> cloth;
        vector<string> name;

        cloth.clear();
        name.clear();

        string a, b;

        for(int i =0; i<n; i++){
            cin >> a >> b;

            if(cloth.count(b) == 0){
                cloth[b] = 1;
                name.push_back(b);
            }
            else cloth[b]++;
        }

        int ans = 1;
        for(int i =0; i<name.size(); i++){
            ans *= (cloth[name[i]] + 1);
        }

        cout << ans - 1 << "\n";
    }
}
