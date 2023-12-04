#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Helper function to find the subset of an element
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Helper function to perform union of two subsets
void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}

// Comparator function to sort edges based on their weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(vector<Edge>& edges, int V) {
    // Sort the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    vector<Edge> mst; // Store the edges of the MST

    // Process each edge in sorted order
    for (const Edge& edge : edges) {
        int rootSrc = find(subsets, edge.src);
        int rootDest = find(subsets, edge.dest);

        // If including this edge doesn't cause a cycle, add it to the MST
        if (rootSrc != rootDest) {
            mst.push_back(edge);
            unionSets(subsets, rootSrc, rootDest);
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << "\n";
    }

    delete[] subsets;
}

int main() {
    clock_t t1,t2;
    float t;
    t1=clock();

    // Original graph represented as an edge list
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, 3}
    };

    // Number of vertices in the original graph
    int V = 4;

    // Print the original graph
    cout << "\nOriginal Graph:\n";
    for (const Edge& edge : edges) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << "\n";
    }
    cout << "\n";

    // Apply Kruskal's algorithm to find the MST
    kruskalMST(edges, V);

    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.\n\n";

    return 0;
}
