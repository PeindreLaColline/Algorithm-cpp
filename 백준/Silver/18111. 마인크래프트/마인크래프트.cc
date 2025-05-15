/*14:56*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int n, m;
ll b;
vector<vector<int> > map;

int time_ans = 2e9;
int height = 0;

bool construction(int num){
    ll time = 0;
    ll block = b;

    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] > num){
                time += (map[i][j] - num)*2;
                block += (map[i][j] - num);
            }
            else if(map[i][j] < num){
                time += (num - map[i][j]);
                block -= (num - map[i][j]);
            }
        }
    }

    if(block < 0) return false; //e변경


    if(time < time_ans){
        time_ans = time;
        height = num;
        return true; //s변경
    }
    else if(time == time_ans){
        if(height < num) height = num;
        return true; //s변경
    }
    else{
        if(block > b) return false; 
        else return true;
    }

}

int main(){

    cin >> n >> m >> b;
    map.resize(n, vector<int>(m));

    int maxi = 0;
    int mini = 987654321;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            maxi = max(map[i][j], maxi);
            mini = min(map[i][j], mini);
        }
    }

    // ll s = 0;
    // ll e = 256;
    // construction(0);
    // while(s<=e){
    //     ll mid = (s+e)/2;

    //     if(construction(mid)) s = mid+1;
    //     else e = mid-1;

    // }
    // construction(256);

    for(int i = mini; i<=maxi; i++){
        construction(i);
    }

    cout << time_ans << " " << height;

}