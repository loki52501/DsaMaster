/*
 * RIVER SIZES - Graph Traversal Problem
 *
 * NETWORKING ANALOGY:
 * Think of this like finding isolated network segments in a topology map.
 * Each '1' is a host, and horizontally/vertically adjacent '1's form a subnet.
 * We need to identify all subnets and count hosts in each.
 *
 * ALGORITHM: Depth-First Search (DFS) with visited tracking
 * Time Complexity: O(w * h) - visit each node once
 * Space Complexity: O(w * h) - worst case stack depth + visited matrix
 */

#include <vector>
#include <stack>
using namespace std;

class RiverSizes {
public:
    /*
     * Main function to find all river sizes
     * Like doing a network discovery scan - we check every IP in the range
     */
    vector<int> riverSizes(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Visited matrix - tracks which nodes we've already explored
        // In networking: like a "scanned hosts" table to avoid re-scanning
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        vector<int> sizes;

        // Scan every position in the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If we found an unvisited river node (1), explore the entire river
                if (matrix[i][j] == 1 && !visited[i][j]) {
                    int riverSize = exploreRiver(i, j, matrix, visited);
                    sizes.push_back(riverSize);
                }
            }
        }

        return sizes;
    }

private:
    /*
     * Explore a single river using Iterative DFS
     * Why iterative? More control, no stack overflow on large rivers
     * Like doing a breadth-first network scan from a gateway
     */
    int exploreRiver(int startRow, int startCol,
                     vector<vector<int>>& matrix,
                     vector<vector<bool>>& visited) {

        int riverSize = 0;
        stack<pair<int, int>> toExplore;
        toExplore.push({startRow, startCol});

        while (!toExplore.empty()) {
            auto [row, col] = toExplore.top();
            toExplore.pop();

            // Skip if already visited (handles duplicates in stack)
            if (visited[row][col]) continue;

            // Mark as visited and increment size
            visited[row][col] = true;
            riverSize++;

            // Explore all 4 neighbors (up, down, left, right)
            // Like checking all directly connected network interfaces
            vector<pair<int, int>> neighbors = getUnvisitedNeighbors(row, col, matrix, visited);

            for (auto [neighborRow, neighborCol] : neighbors) {
                toExplore.push({neighborRow, neighborCol});
            }
        }

        return riverSize;
    }

    /*
     * Get valid unvisited neighbors that are part of a river
     * Four directions: up, down, left, right (NO diagonals)
     */
    vector<pair<int, int>> getUnvisitedNeighbors(int row, int col,
                                                  vector<vector<int>>& matrix,
                                                  vector<vector<bool>>& visited) {
        vector<pair<int, int>> neighbors;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Direction vectors: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            // Check bounds, if it's a river node (1), and if unvisited
            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                matrix[newRow][newCol] == 1 &&
                !visited[newRow][newCol]) {
                neighbors.push_back({newRow, newCol});
            }
        }

        return neighbors;
    }
};

/*
 * ALTERNATIVE: Recursive DFS (simpler but can stack overflow)
 * Kept here for learning - this is more intuitive but less production-ready
 */
class RiverSizesRecursive {
public:
    vector<int> riverSizes(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<int> sizes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1 && !visited[i][j]) {
                    int size = dfs(i, j, matrix, visited);
                    sizes.push_back(size);
                }
            }
        }

        return sizes;
    }

private:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Base cases
        if (row < 0 || row >= rows || col < 0 || col >= cols) return 0;
        if (matrix[row][col] == 0 || visited[row][col]) return 0;

        visited[row][col] = true;
        int size = 1;

        // Explore all 4 directions
        size += dfs(row - 1, col, matrix, visited); // up
        size += dfs(row + 1, col, matrix, visited); // down
        size += dfs(row, col - 1, matrix, visited); // left
        size += dfs(row, col + 1, matrix, visited); // right

        return size;
    }
};

// Test the solution
#include <iostream>

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    RiverSizes solution;

    // Test case from problem
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };

    /*
     * Visualizing the rivers:
     * River 1 (size 1): [0,0], [1,0]
     * River 2 (size 2): [0,3]
     * River 3 (size 2): [1,2], [2,2], [3,2], [4,2], [4,3]
     * River 4 (size 2): [2,4], [3,4]
     * River 5 (size 5): [3,0]
     *                   [4,0]
     *
     * Expected output: [1, 2, 2, 2, 5] (or any order)
     */

    vector<int> result = solution.riverSizes(matrix);

    cout << "River sizes: ";
    printVector(result);

    return 0;
}

/*
 * KEY TAKEAWAYS (memorize these):
 *
 * 1. PATTERN RECOGNITION: 2D grid + find connected components = DFS/BFS
 *    - Similar to: island counting, flood fill, network segments
 *
 * 2. VISITED MATRIX: Always needed to avoid infinite loops and re-processing
 *    - Alternative: modify input matrix (mark 1s as 0s) if mutation allowed
 *
 * 3. ITERATIVE vs RECURSIVE DFS:
 *    - Iterative: Use explicit stack, safer for large inputs
 *    - Recursive: Cleaner code, but risk stack overflow
 *
 * 4. NEIGHBOR EXPLORATION:
 *    - Use direction arrays for cleaner code: dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1}
 *    - Always validate: bounds check AND condition check
 *
 * 5. NETWORKING PARALLEL:
 *    - Finding rivers = Finding network segments/subnets
 *    - DFS = Following routing paths to map a subnet
 *    - Visited = Already scanned hosts table
 *
 * This pattern appears in: packet routing, network topology discovery,
 * distributed system partition detection, etc.
 */
