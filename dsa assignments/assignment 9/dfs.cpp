#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int n;

void DFS_Util(int u, int visited[])
{
    visited[u] = 1;
    cout << u << " ";

    for (int v = 0; v < n; v++)
    {
        if (graph[u][v] && visited[v] == 0)
            DFS_Util(v, visited);
    }
}

void DFS(int start)
{
    int visited[MAX] = {0};
    cout << "DFS: ";
    DFS_Util(start, visited);
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    DFS(start);
}