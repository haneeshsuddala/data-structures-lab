#include <iostream>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    int adj[100][100] = {0};
    int u, v;

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}