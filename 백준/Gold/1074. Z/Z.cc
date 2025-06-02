/*14:51*/
#include <iostream>
#include <math.h>
using namespace std;

int n, r, c;

int get_area(int x, int y, int size){
    if(r < y+size){
        if(c < x+size) return 1;
        else if(c >= x+size) return 2;
    }
    else if(r >= y+size){
        if(c < x+size) return 3;
        else if(c >= x+size) return 4;
    }
}

void dfs(int x, int y, int val, int size){
    int area = get_area(x, y, size);
    if(c==x && r==y) {
        cout << val;
        return;
    }
    if(area == 1) dfs(x, y, val, size/2);
    else if(area == 2) dfs(x+size, y, val+size*size*1, size/2);
    else if(area == 3) dfs(x, y+size, val+size*size*2, size/2);
    else if(area == 4) dfs(x+size, y+size, val+size*size*3, size/2);
    
}

int main(){
    cin >> n >> r >> c;
 
    dfs(0, 0, 0, pow(2, n-1));
}