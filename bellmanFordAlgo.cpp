#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(int vertices, int edges, const vector<Edge>& graph, int source) {
    vector<int> distance(vertices, numeric_limits<int>::max());
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < vertices - 1; ++i) {
        for (const Edge& edge : graph) {
            if (distance[edge.source] != numeric_limits<int>::max() &&
                distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge& edge : graph) {
        if (distance[edge.source] != numeric_limits<int>::max() &&
            distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains negative-weight cycle. Bellman-Ford doesn't work in this case.\n";
            return;
        }
    }

    // Print the distances
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "To vertex " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<Edge> graph(edges);

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < edges; ++i) {
        cin >> graph[i].source >> graph[i].destination >> graph[i].weight;
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    bellmanFord(vertices, edges, graph, sourceVertex);

    return 0;
}
