/*15:57*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
map<int, string> in_to_st;
map<string, int> st_to_in;

int get_num(string s){

    int num = 0;
    for(int i =0; i<s.size(); i++){
        num += (s[i]-'0');
        num *= 10;
    }

    return num /= 10;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    string tmp;
    for(int i =1; i<=n; i++){
        cin >> tmp;
        in_to_st[i] = tmp;
        st_to_in[tmp] = i;
    }

    for(int i =0; i<m; i++){
        cin >> tmp;
        if(tmp[0] >= 48 && tmp[0] <= 57){
            cout << in_to_st[get_num(tmp)] << "\n";
        }
        else{
            cout << st_to_in[tmp] << "\n";
        }
    }
}