/*18:17*/
#include <iostream>
#include <vector>
using namespace std;

struct po{
    int a;
    int b;
    int val;

    po() {}
    po(int _a, int _b, int _val) : a(_a), b(_b), val(_val) {}
};

int test;
int n, m, w;

vector<po> v;
vector<int> dist;
vector<int> comp;

void bellman(){
    for(int i =0; i<v.size(); i++){
        if(dist[v[i].a] != 987654321 && dist[v[i].b] > dist[v[i].a] + v[i].val){
            dist[v[i].b] = dist[v[i].a] + v[i].val;
        }
    }
}

int main(){

    cin >> test;

    for(int t = 0; t<test; t++){
        cin >> n >> m >> w;

        v.clear();

        dist.clear();
        dist.resize(n+1, 987654321);
        dist[0] = 0;

        comp.clear();

        int a, b, val;

        for (int i = 1; i <= n; i++) {
            v.push_back(po(0, i, 0));
        }

        for(int i =0; i<m; i++){
            cin >> a >> b >> val;

            v.push_back(po(a, b, val));
            v.push_back(po(b, a, val));
        }

        for(int i = 0; i<w; i++){
            cin >> a >> b >> val;
            
            v.push_back(po(a, b, (-1)*val));
        }

        for(int i =0; i<n-1; i++){
            bellman();
        }

        comp = dist;

        bellman();

        bool yes = false;
        for(int i=1; i<=n; i++){
            if(comp[i] > dist[i]){
                yes = true;
                break;
            }
        }

        if(yes) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

}