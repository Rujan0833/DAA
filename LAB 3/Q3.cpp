/*Theory of Prim's Algorithm:

    Prim's Algorithm: Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. It starts with an arbitrary node and grows the tree by adding the cheapest edge that connects a vertex in the tree to a vertex outside the tree. This process continues until all vertices are included in the MST.

    Complexities:
        Time Complexity:
            Best Case: O(V2)O(V2) where VV is the number of vertices. This occurs when the graph is dense and represented using an adjacency matrix.
            Worst Case: O(V2)O(V2) where VV is the number of vertices. This also occurs when the graph is dense and represented using an adjacency matrix.
            Average Case: O(V2)O(V2) where VV is the number of vertices.
        Space Complexity:
            O(V2)O(V2) for storing the adjacency matrix.
        Auxiliary Space Complexity:
            O(V)O(V) for storing key values, parent array, and mstSet array.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

void primMST(const vector<vector<int>>& graph, int V, int& total_steps) {
    vector<int> parent(V);
    vector<int> key(V);

    vector<bool> mstSet(V, false);

    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        total_steps += V; // Count the number of iterations (V) as steps
    }

    printMST(parent, graph, V);
}

int main() {
    const int V = 5;
    const vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int total_steps = 0; // Initialize total steps counter

    primMST(graph, V, total_steps);

    cout << "Total number of steps: " << total_steps << endl; // Print total steps

    return 0;
}
