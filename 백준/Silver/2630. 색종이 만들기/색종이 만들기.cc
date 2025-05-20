/*10:36*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//구조체
//x, y는 조사할 색종이의 왼쪽 위 좌표
//size는 조사할 색종이의 크기
struct info{
    int x;
    int y;
    int size;

    info(int x_, int y_, int size_) : x(x_), y(y_), size(size_) {}
};

int n;
vector<vector<int> > v;
int white = 0;
int blue = 0;

//정해진 구역 내의 색종이 색이 다 같은지 확인
bool check(info info){
    int x = info.x;
    int y = info.y;
    int size = info.size;
    int color = v[y][x];

    for(int i =y; i<y+size; i++){
        for(int j =x; j<x+size; j++){
            if(color == v[i][j]) continue;
            else return false;
        }
    }
    
    return true;
}

//현재 구역의 색종이 색이 전부 동일하지 않다면 4등분해서 queue에 저장
//동일하다면 blue 혹은 white에 카운트
void dfs(){
    queue<info> q;
    q.push(info(1, 1, n));

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int size = q.front().size;
        q.pop();

        if(!check(info(x, y, size))){    
            size/=2;
            q.push(info(x, y, size));
            q.push(info(x+size, y, size));
            q.push(info(x, y+size, size));
            q.push(info(x+size, y+size, size));
        }
        else{
            if(v[y][x] == 1) blue++;
            else white++;
        }
    }
}

int main(){
    cin >> n;
    v.resize(n+1, vector<int>(n+1));

    //흰색0, 파란색1
    //좌표 보기 편하게 하려고 1부터 시작
    for(int i =1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> v[i][j];
        }
    }

    dfs();

    cout << white <<endl;
    cout << blue << endl;

}
