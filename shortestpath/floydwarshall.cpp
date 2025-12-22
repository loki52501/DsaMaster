#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

void printSolution(const vector<vector<int>>& dist, int V) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V));

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices
    // k is the intermediate vertex
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    printSolution(dist, V);
}

int main() {
    int V = 4;

    // Example graph represented as adjacency matrix
    // INF means there is no direct edge between vertices
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    cout << "Original graph (adjacency matrix):\n";
    printSolution(graph, V);
    cout << "\n";

    floydWarshall(graph, V);

    return 0;
}
