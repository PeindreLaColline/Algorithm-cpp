/*10:47*/
    /*
    case 1 (n==1)
    OOIOIOIOIIOII
    0012345671231

    case 2 (n==2)
    OOIOIOIOIIOII
    0012345671231
    */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
string s;
vector<int> v;

int main(){
    cin >> n >> m;
    cin >> s;

    int tmp;
    bool aie;
    if(s[0] == 'I'){
        aie = true;
        tmp = 1;
    } 
    else{
        aie = false;
        tmp = 0;
    }

    int ans = 0;
    int cnt = 1 + n*2;
    for(int i = 1; i<s.size(); i++){
        if(aie){
            if(s[i] == 'I'){
                aie = true;
                tmp = 1;
            }
            else{
                aie = false;
                tmp++;
            }
        }
        else{
            if(s[i] == 'I'){
                aie = true;
                tmp++;
                if(tmp >= cnt) ans++;
            }
            else{
                aie = false;
                tmp = 0;
            }
        }
        
    }

    cout << ans;

}
