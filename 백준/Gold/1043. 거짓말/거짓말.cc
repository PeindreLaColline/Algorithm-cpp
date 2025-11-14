#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

int n, m;
int cnt_truth;
unordered_set<int> truth;
vector<vector<int> > party;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    cin >> cnt_truth;
    int tmp;
    for(int i =0; i<cnt_truth; i++){
        cin >> tmp;
        truth.insert(tmp);
    }

    party.resize(m);
    for(int i =0; i<m; i++){
        cin >> tmp;
        int idx;
        for(int j =0; j<tmp; j++){
            cin >> idx;
            party[i].push_back(idx);
        }
    }

    int size = -1;
    bool done;
    while(true){
        if(size == truth.size()) break;
        size = truth.size();
        
        for(int i = 0; i<m; i++){
            done = false;
            for(int j =0; j<party[i].size(); j++){
                if(truth.find(party[i][j]) != truth.end()){
                    done = true;
                    break;
                }
            }
            if(done){
                for(int j = 0; j< party[i].size(); j++){
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