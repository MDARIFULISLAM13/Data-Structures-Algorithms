#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int n, m;
    cin >> n >> m;

    // Adjacency list to store the graph
    vector<vector<pair<int, long long>>> graph(n + 1);

    // Reading the flight connections
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); // Store the flight as an edge
    }

    // Distance array
    vector<long long> distance(n + 1, INF);
    distance[1] = 0; // Distance from city 1 to itself is 0

    // Min-heap priority queue for Dijkstra's algorithm
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 1); // Start from city 1

    while (!pq.empty()) {
        pair<long long, int> p = pq.top(); // Retrieve the top element
        pq.pop();

        long long dist = p.first; // The distance
        int city = p.second;      // The city

        // If we have found a longer distance, skip this entry
        if (dist > distance[city]) continue;

        // Explore neighbors
        for (size_t i = 0; i < graph[city].size(); ++i) {
            int neighbor = graph[city][i].first; // Neighbor city
            long long weight = graph[city][i].second; // Flight length

            if (distance[city] + weight < distance[neighbor]) {
                distance[neighbor] = distance[city] + weight;
                pq.emplace(distance[neighbor], neighbor);
            }
        }
    }

    // Output the result
    for (int i = 1; i <= n; ++i) {
        cout << distance[i] << " ";
    }
    cout << endl;

    return 0;
}
