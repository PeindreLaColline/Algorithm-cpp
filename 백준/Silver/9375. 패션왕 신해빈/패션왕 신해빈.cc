/*11:55*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){

    int test;
    cin >> test;

    int n;
    for(int t = 0; t<test; t++){
        
        cin >> n;

        map<string, int> cloth;
        vector<string> name;

        cloth.clear();
        name.clear();

        string a, b;

        for(int i =0; i<n; i++){
            cin >> a >> b;

            if(cloth.count(b) == 0){
                cloth[b] = 1;
                name.push_back(b);
            }
            else cloth[b]++;
        }

        int ans = 1;
        for(int i =0; i<name.size(); i++){
            ans *= (cloth[name[i]] + 1);
        }

        cout << ans - 1 << "\n";
    }
}