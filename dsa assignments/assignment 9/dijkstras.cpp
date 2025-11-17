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

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int minDist = INT_MAX, u;

        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Dijkstra (from " << start << "):\n";
    for (int i = 0; i < n; i++)
        cout << "Distance to " << i << " = " << dist[i] << endl;
}