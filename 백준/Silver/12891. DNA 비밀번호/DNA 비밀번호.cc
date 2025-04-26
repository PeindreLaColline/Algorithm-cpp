/*14:03*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int s, p;
vector<int> v(4);
vector<int> cur(4, 0);
string st;

int ans = 0;

void valid(){

    for(int i = 0; i<4; i++){
        if(v[i] > cur[i]) return;
    }
    ans++;
}

int main(){
    cin >> s >> p;
    cin >> st;
    for(int i =0; i<4; i++){
        cin >> v[i];
    }

    for(int i =0; i<p; i++){
        if(st[i] == 'A'){
            cur[0]++;
        }
        else if(st[i] == 'C'){
            cur[1]++;
        }
        else if(st[i] == 'G'){
            cur[2]++;
        }
        else{
            cur[3]++;
        }
        
    }
    valid();

    for(int i = 1; i<=s-p; i++){
        if(st[i-1] == 'A'){
            cur[0]--;
        }
        else if(st[i-1] == 'C'){
            cur[1]--;
        }
        else if(st[i-1] == 'G'){
            cur[2]--;
        }
        else{
            cur[3]--;
        }

        if(st[i+p-1] == 'A'){
            cur[0]++;
        }
        else if(st[i+p-1] == 'C'){
            cur[1]++;
        }
        else if(st[i+p-1] == 'G'){
            cur[2]++;
        }
        else{
            cur[3]++;
        }
        valid();
    }

    cout << ans;
}