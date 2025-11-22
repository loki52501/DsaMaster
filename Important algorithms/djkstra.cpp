#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int n = edges.size();
    vector<int> dist(n, -1);
    vector<bool> visited(n, false);

    // Initialize distances
    // We'll use -1 to represent infinity in the final output, 
    // but internally it's easier to use INT_MAX for comparisons.
    // However, the problem asks for -1 for unreachable.
    // Let's use a separate vector for internal calculations or just handle -1 carefully.
    // Actually, using INT_MAX is standard. We can convert to -1 at the end.
    vector<int> d(n, INT_MAX);
    
    d[start] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        int minVal = INT_MAX;

        // Find the unvisited vertex with the smallest distance
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && d[j] < minVal) {
                minVal = d[j];
                u = j;
            }
        }

        // If no reachable vertex is left, break
        if (u == -1) {
            break;
        }

        visited[u] = true;

        // Relax edges
        for (auto& edge : edges[u]) {
            int v = edge[0];
            int weight = edge[1];

            if (d[u] != INT_MAX && d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
            }
        }
    }

    // Convert INT_MAX to -1 for the output format
    for(int i=0; i<n; ++i) {
        if(d[i] == INT_MAX) {
            dist[i] = -1;
        } else {
            dist[i] = d[i];
        }
    }

    return dist;
}

