/*
왼쪽 끝이 B인 경우를 기준으로
1. 좌표가 (i, j)이고 i%2 == j%2인 경우에 해당 자리는 B가 되어야 함
2. 좌표가 (i, j)이고 i%2 != j%2인 경우에 해당 자리는 W가 되어야 함

풀이 과정
1. 체스판 입력받을 때 해당 조건을 만족하지 않으면 change[i][j]를 1로 둠
2. 8*8 사이즈로 잘랐을 때 내부의 1의 개수의 합 = 바뀌어야하는 자리 개수의 합 = tmp
3. 64-tmp = 왼쪽 끝이 W일 때 바뀌어야하는 자리 개수의 합
4. 이 중 최소값이 답
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans = 98765432;
vector<vector<int> > change;

int get_sum(int x, int y){
    int tmp = 0;
    for(int i = y; i<y+8; i++){
        for(int j = x; j<x+8; j++){
            tmp += change[i][j];
        }
    }
    return tmp;
}

void get_ans(){
    int tmp;
    for(int i =0; i<=n-8; i++){
        for(int j =0; j<=m-8; j++){
            tmp = get_sum(j, i);
            ans = min(ans, min(tmp, 64-tmp));
        }
    }
}

int main(){
    cin >> n >> m;

    vector<int> itmp(m, 0);
    change.resize(n, itmp);
    
    char ctmp;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> ctmp;
            if(ctmp == 'W' && i%2 == j%2) change[i][j] = 1;
            else if(ctmp == 'B' && i%2 != j%2) change[i][j] = 1;
        }
    }

    get_ans();
    cout << ans;
}
