#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<int> adj[100];
    int u, v;

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int x : adj[i]) cout << x << " ";
        cout << endl;
    }
}