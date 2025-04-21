/*16:02*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<bool> v(21, false);
    vector<bool> v_all(21, true);
    vector<bool> v_empty(21, false);

    string tmp;
    int num;
    for(int i =0; i<n; i++){

        cin >> tmp;
        if(tmp == "all"){
            v = v_all;
        }
        else if(tmp == "empty"){
            v = v_empty;
        }
        else{
            cin >> num;

            if(tmp == "add"){
                v[num] = true;
            }
            else if(tmp == "remove"){
                v[num] = false;
            }
            else if(tmp == "check"){
                if(v[num]){
                    cout << 1 << "\n";
                }
                else{
                    cout << 0 << "\n";
                }
            }
            else if(tmp == "toggle"){
                v[num] = !v[num];
            }
        }
    }
}