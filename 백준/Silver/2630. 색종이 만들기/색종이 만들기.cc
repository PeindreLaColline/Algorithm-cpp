/*10:36*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    for(int i =1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> v[i][j];
        }
    }

    dfs();

    cout << white <<endl;
    cout << blue << endl;

}