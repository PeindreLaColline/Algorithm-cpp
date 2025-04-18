/*17:31*/
/*18:04*/
#include <iostream> 
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int n, m;
vector<vector<int> > map;
vector<pair<int, int> > space;
queue<pair<int, int> > virus;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int ans = 0;

int pn = 1;

void bfs(){
    vector<vector<int> > c_map = map;

    for(int s1 = 0; s1<space.size(); s1++){
        c_map[space[s1].first][space[s1].second] = 1;

        for(int s2 = s1+1; s2<space.size(); s2++){
            c_map[space[s2].first][space[s2].second] = 1;

            for(int s3 = s2+1; s3<space.size(); s3++){
                c_map[space[s3].first][space[s3].second] = 1;

                vector<vector<int> > cc_map = c_map;
                queue<pair<int, int> > cc_virus = virus;

                while(!cc_virus.empty()){
                    int x = cc_virus.front().second;
                    int y = cc_virus.front().first;
                    cc_virus.pop();

                    for(int i =0; i<4; i++){
                        int cx = x + dir[i][0];
                        int cy = y + dir[i][1];
                        
                        if(cx<0 || cx >= m || cy<0 || cy >= n) continue;

                        if(cc_map[cy][cx] == 0){
                            cc_virus.push(make_pair(cy, cx));
                            cc_map[cy][cx] = 2;
                        }
                    }
                }

                int tmpans = 0;
                for(int i =0; i<n; i++){
                    for(int j = 0; j<m; j++){
                        if(cc_map[i][j] == 0){tmpans++;}
                    }
                }
                ans = max(ans, tmpans);

                // cout << "trial " << pn << endl;
                // for(int i =0; i<n; i++){
                //     for(int j = 0; j<m; j++){
                //         cout << cc_map[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout<<endl;
                // pn++;

                c_map[space[s3].first][space[s3].second] = 0;
            }

            c_map[space[s2].first][space[s2].second] = 0;
        }

        c_map[space[s1].first][space[s1].second] = 0;
    }


}

int main(){
    cin >> n >> m;
    vector<int> tmpmap(m);
    map.resize(n, tmpmap);

    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0) space.push_back(make_pair(i, j));
            else if(map[i][j] == 2) virus.push(make_pair(i, j));    
        }
    }

    bfs();
    cout<< ans;
}