/*11:09*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> sti;
map<int, string> its;

int n, m;

string get_name(int num){
    return its[num];
}

int get_num(string s){
    return sti[s];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    string s;
    for(int i = 1; i<=n; i++){
        cin >> s;
        sti[s] = i;
        its[i] = s;
    }

    for(int i =0; i<m; i++){
        cin >> s;
        if(s[0] - '0' >= 1 && s[0] - '0' <= 9) cout << get_name(stoi(s)) << "\n";
        else cout << get_num(s) << "\n";
    }
}
