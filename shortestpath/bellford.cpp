#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void printSolution(const vector<int>& dist, int V) {
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << "\t\tINF\n";
        else
            cout << i << "\t\t" << dist[i] << "\n";
    }
}

bool bellmanFord(vector<Edge>& edges, int V, int E, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    // If we get a shorter path, then there is a negative cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return false;
        }
    }

    printSolution(dist, V);
    return true;
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Create edges: {source, destination, weight}
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    cout << "Graph edges:\n";
    cout << "Source -> Destination : Weight\n";
    for (const auto& edge : edges) {
        cout << edge.src << " -> " << edge.dest << " : " << edge.weight << "\n";
    }
    cout << "\n";

    int source = 0;
    cout << "Running Bellman-Ford from source vertex " << source << "\n\n";
    bellmanFord(edges, V, E, source);

    cout << "\n\nExample with negative cycle:\n";
    vector<Edge> negCycleEdges = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 1, -1}
    };

    cout << "Graph edges:\n";
    cout << "Source -> Destination : Weight\n";
    for (const auto& edge : negCycleEdges) {
        cout << edge.src << " -> " << edge.dest << " : " << edge.weight << "\n";
    }
    cout << "\n";

    bellmanFord(negCycleEdges, 4, 4, 0);

    return 0;
}
