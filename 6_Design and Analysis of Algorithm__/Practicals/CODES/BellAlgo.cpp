#include <iostream>
#include <vector>
#include <limits>
#include <time.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(const vector<Edge>& edges, int V, int source) {
    vector<int> distance(V, numeric_limits<int>::max());
    distance[source] = 0;
    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.source] != numeric_limits<int>::max() &&
                distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }
    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.source] != numeric_limits<int>::max() &&
            distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains a negative-weight cycle.\n";
            return;
        }
    }
    // Print the original graph
    cout << "Original Graph:\n";
    for (const Edge& edge : edges) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << "\n";
    }
    cout << "\n";
    // Print the distances from the source to all vertices
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    clock_t t1,t2;
    float t;
    t1=clock();
    // Example graph represented as an edge list
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, -3}
    };
    // Number of vertices in the graph
    int V = 4;
    // Specify the source vertex
    int source = 0;
    // Apply Bellman-Ford algorithm
    bellmanFord(edges, V, source);

    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;

    cout << "\nProcessing Time is " << t << " seconds.\n\n";   
     
    return 0;
}
