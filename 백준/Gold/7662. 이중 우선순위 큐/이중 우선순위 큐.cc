/*00:26*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare1{
    bool operator()(pair<int, int> const &a, pair<int, int> const &b){
        return a.second > b.second;
    }
};

struct compare2{
    bool operator()(pair<int, int> const &a, pair<int, int> const &b){
        return a.second < b.second;
    }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    for(int t = 0; t<test_case; t++){
        int n;
        cin>> n;

        priority_queue<pair<int, int>, vector<pair<int, int> >, compare1 > pq1;
        priority_queue<pair<int, int>, vector<pair<int, int> >, compare2 > pq2;
        vector<bool> visited(n, false);
        string s;
        int num;

        for(int i =0; i<n; i++){
            cin >> s >> num;
            if(s=="I"){
                pq1.push(make_pair(i, num));
                pq2.push(make_pair(i, num));
            }
            else{
                if(num == -1){
                    while(!pq1.empty()){
                        if(!visited[pq1.top().first]){
                            visited[pq1.top().first] = true;
                            pq1.pop();
                            break;
                        }
                        pq1.pop();
                    }
                }
                else{
                    while(!pq2.empty()){
                        if(!visited[pq2.top().first]){
                            visited[pq2.top().first] = true;
                            pq2.pop();
                            break;
                        }
                        pq2.pop();
                    }
                }
 
            }

        }
        
        while(!pq1.empty() && visited[pq1.top().first]){
            pq1.pop();
        }
        while(!pq2.empty() && visited[pq2.top().first]){
            pq2.pop();
        }

        if(pq1.empty() && pq2.empty()){
            cout << "EMPTY" << "\n";
        }
        else{
            cout << pq2.top().second << " " << pq1.top().second <<"\n";
        }

    }

}