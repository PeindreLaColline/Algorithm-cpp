#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> subset(s1.size() + 1, 0);  // subset 벡터의 크기를 s1.size()+1로 설정
    for (int i = 1; i <= s2.size(); i++) {
        int prev = 0;  // 이전 행의 결과를 저장할 변수
        for (int j = 1; j <= s1.size(); j++) {
            int temp = subset[j];  // subset[j]를 임시로 저장해둠
            if (s1[j - 1] == s2[i - 1]) {
                subset[j] = prev + 1;
            }
            else {
                subset[j] = max(subset[j], subset[j - 1]);
            }
            prev = temp;  // 다음 반복을 위해 prev를 업데이트
        }
    }

    cout << subset[s1.size()] << endl;  // LCS의 길이 출력
    return 0;
}
