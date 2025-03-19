/*22:30*/
/*문제에서 시키는대로 그대로, 구역 나눠서 그 안에 색이 전부 같으면 패스, 아니면 큐에 넣어서 다음 차례에 또 검사*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Point{
    public:
        int x;
        int y;
        int cnt; //구역 사이즈 - 예를 들어 전체 종이 확인이라면 n과 같고, 첫 번째로 등분한 다음에 확인하는 거라면 n/3

        Point(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int n;
vector<vector<int> > v;
queue<Point> q;
vector<int> ans(3, 0);

bool is_full(int x, int y, int cnt, int num){ //정해진 구역 안이 모두 같은 색인지 확인
    for(int i=y; i < y+cnt; i++){
        for(int j=x; j < x+cnt; j++){
            if(num != v[i][j]) return false;
        }
    }
    return true;
}

void back(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if(is_full(x, y, cnt, v[y][x])){ //구역 내 색 전부 동일한지 확인
            if(v[y][x] == -1) ans[0]++;
            else if(v[y][x] == 0) ans[1]++;
            else if(v[y][x] == 1) ans[2]++;
            continue;
        }
        else{ //만약에 같지 않다면 9등분 한 종이의 왼쪽 위 좌표를 큐에 저장
            cnt /= 3;
            q.push(Point(x, y, cnt)); q.push(Point(x+cnt, y, cnt)); q.push(Point(x+cnt+cnt, y, cnt));
            q.push(Point(x, y+cnt, cnt));q.push(Point(x+cnt, y+cnt, cnt)); q.push(Point(x+cnt+cnt, y+cnt, cnt));
            q.push(Point(x, y+cnt+cnt, cnt)); q.push(Point(x+cnt, y+cnt+cnt, cnt)); q.push(Point(x+cnt+cnt, y+cnt+cnt, cnt));
            continue;
        }
    }
}

int main(){
    cin >> n;
    vector<int> tmp(n);
    v.resize(n, tmp);
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> v[i][j];
        }
    }

    q.push(Point(0, 0, n));
    back();

    for(int i =0; i<3; i++){
        cout<<ans[i]<<endl;
    }
}
