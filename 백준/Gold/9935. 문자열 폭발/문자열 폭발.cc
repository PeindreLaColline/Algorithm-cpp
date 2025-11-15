//15:45
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, explode;
    cin >> s >> explode;
    string result;

    for(int i =0; i<s.size(); i++){
        result.push_back(s[i]);
        if((result.size() >= explode.size()) && (result.substr(result.size() - explode.size()) == explode)){
            result.erase(result.size() - explode.size());
        }
    }
    if(result.empty()) cout << "FRULA";
    else cout << result;
}