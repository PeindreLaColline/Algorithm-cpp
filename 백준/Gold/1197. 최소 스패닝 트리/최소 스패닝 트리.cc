#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int from = 0;
    int to = 0;
    int weight = 0;

    Edge() {}
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

bool compare(Edge a, Edge b) {
	return a.weight < b.weight;
}

int v, e;
Edge *edge;
vector<int> parent;

void make() {
	parent.resize(v + 1);
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
}

int find(int a){
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

bool unite(int a, int b) {
	int ar = find(a);
	int br = find(b);
	if (ar == br) return false;
	parent[br] = ar;
	return true;
}

int main() {
	cin >> v >> e;
	
	make();
	edge = new Edge[e];
	for (int i = 0; i < e; i++) {
		cin >> edge[i].from >> edge[i].to >> edge[i].weight;
	}
	sort(edge, edge + e, compare);
	
	int sum = 0, cnt = 0;
	for (int i = 0; i < e; i++) {
		if (unite(edge[i].from, edge[i].to)) {
			sum += edge[i].weight;
			if (++cnt == v - 1) break;
		}
	}

	cout << sum;
}