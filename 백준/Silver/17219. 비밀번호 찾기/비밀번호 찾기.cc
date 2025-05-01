/*20:30*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n, m;
map<string, string> note;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    string site, pw;

    for(int i =0; i<n; i++){
        cin >> site >> pw;
        note[site] = pw;
    }

    for(int i =0; i<m; i++){
        cin >> site;
        cout << note[site] <<"\n";
    }
}