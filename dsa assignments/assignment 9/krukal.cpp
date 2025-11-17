#include <iostream>
using namespace std;

#define MAX 100

struct Edge {
    int u, v, w;
};

int graph[MAX][MAX];
int parent[MAX];
int n;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    Edge edges[MAX * MAX];
    int e = 0;

    // convert matrix to edge list
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] != 0)
            {
                edges[e].u = i;
                edges[e].v = j;
                edges[e].w = graph[i][j];
                e++;
            }

    // init parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // sort edges by weight
    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[j].w < edges[i].w)
            {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }

    cout << "Kruskal MST:\n";

    int count = 0;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            cout << u << " - " << v << " : " << edges[i].w << endl;
            union_set(u, v);
            count++;
        }

        if (count == n - 1)
            break;
    }
}