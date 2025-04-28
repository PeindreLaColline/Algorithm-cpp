/*11:22*/
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

    string s;
    vector<bool> set(21, false);
    vector<bool> all(21, true);
    vector<bool> emp(21, false);

    int num;
    for(int i =0; i<n; i++){
        cin >> s;

        if(s == "add"){
            cin >> num;
            set[num] = true;
        }
        else if(s=="remove"){
            cin >> num;
            set[num] = false;
        }
        else if(s=="check"){
            cin >> num;
            cout << set[num] << "\n";
        }
        else if(s=="toggle"){
            cin >> num;
            set[num] = !set[num];
        }
        else if(s=="all"){
            set = all;
        }
        else{
            set = emp;
        }
    }

}