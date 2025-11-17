//15:23
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n, m;
int truth_num;
vector<vector<int> > party;
unordered_set<int> truth;

int main(){
    cin >> n >> m;
    cin >> truth_num;
    party.resize(m, vector<int>());
    
    int tmp;
    for(int i =0; i<truth_num; i++){
        cin >> tmp;
        truth.insert(tmp);
    }

    for(int i =0; i<m; i++){
        cin >> tmp;
        party[i].resize(tmp);
        for(int j = 0; j<tmp; j++){
            cin >> party[i][j];
        }
    }

    int size=-1;
    while(true){
        if(size == truth.size()) break;
        size = truth.size();

        for(int i =0; i<m; i++){
            bool change = false;
            for(int j =0; j<party[i].size(); j++){
                if(truth.find(party[i][j]) != truth.end()){
                    change = true;
                    break;
                }
            }

            if(change){
                for(int j = 0; j<party[i].size(); j++){
                    truth.insert(party[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int i =0; i<m; i++){
        if(truth.find(party[i][0]) == truth.end()) ans++;
    }

    cout << ans;
}