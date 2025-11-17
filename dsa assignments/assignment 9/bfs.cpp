#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int n;

void BFS(int start)
{
    int visited[MAX] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
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

    BFS(start);
}