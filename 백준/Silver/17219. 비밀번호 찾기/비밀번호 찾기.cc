/*20:30*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n, m;
map<string, string> note; //map으로 사이트랑 비밀번호 저장

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //input
    cin >> n >> m;

    string site, pw;

    for(int i =0; i<n; i++){
        cin >> site >> pw;
        note[site] = pw;
    }

    //output
    for(int i =0; i<m; i++){
        cin >> site;
        cout << note[site] <<"\n";
    }
}
