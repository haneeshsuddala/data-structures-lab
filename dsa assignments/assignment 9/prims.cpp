#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int n;

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int key[MAX], parent[MAX], visited[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    key[start] = 0;

    for (int k = 0; k < n - 1; k++)
    {
        int minKey = INT_MAX, u;

        for (int i = 0; i < n; i++)
            if (!visited[i] && key[i] < minKey)
            {
                minKey = key[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST:\n";
    for (int i = 0; i < n; i++)
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}