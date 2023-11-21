#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int destination, weight;
};

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjacencyList;

    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight}); // for undirected graph
    }

    void dijkstra(int source) {
        vector<int> distance(vertices, numeric_limits<int>::max());
        distance[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const Edge& edge : adjacencyList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        // Print the distances
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "To vertex " << i << ": " << distance[i] << "\n";
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < edges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    graph.dijkstra(sourceVertex);

    return 0;
}
