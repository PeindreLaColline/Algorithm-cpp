/*22:30*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Point{
    public:
        int x;
        int y;
        int cnt;

        Point(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int n;
vector<vector<int> > v;
queue<Point> q;
vector<int> ans(3, 0);

bool is_full(int x, int y, int cnt, int num){
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

        if(is_full(x, y, cnt, v[y][x])){
            if(v[y][x] == -1) ans[0]++;
            else if(v[y][x] == 0) ans[1]++;
            else if(v[y][x] == 1) ans[2]++;
            continue;
        }
        else{
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