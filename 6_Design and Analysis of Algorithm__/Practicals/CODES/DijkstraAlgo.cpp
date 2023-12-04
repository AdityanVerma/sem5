#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <ctime>

using namespace std;

// Structure to represent a graph edge
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a graph vertex
struct Vertex {
    int index;
    int distance;
};

// Comparison function for the priority queue
struct CompareVertex {
    bool operator()(const Vertex& a, const Vertex& b) {
        return a.distance > b.distance;
    }
};
// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<Edge>>& graph, int source) {
    int V = graph.size();
    vector<int> distance(V, numeric_limits<int>::max());
    vector<bool> visited(V, false);
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    pq.push({source, 0});
    distance[source] = 0;
    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({v, distance[v]});
            }
        }
    }

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
    // Example graph represented as an adjacency list
    vector<vector<Edge>> graph = {
        {{1, 2}, {2, 4}},
        {{0, 2}, {2, 1}, {3, 5}},
        {{0, 4}, {1, 1}, {3, 3}},
        {{1, 5}, {2, 3}}
    };

    // Print the original graph
    cout << "\nOriginal Graph:-\n\n";
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Vertex " << i << ": ";
        for (const Edge& edge : graph[i]) {
            cout << "(" << edge.destination << ", " << edge.weight << ") ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Specify the source vertex
    int source = 0;

    // Apply Dijkstra's algorithm
    dijkstra(graph, source);

    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.\n\n";

    return 0;
}
