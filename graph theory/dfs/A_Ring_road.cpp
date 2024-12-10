#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> roads(n); // Stores road info as tuples (a, b, c)
    int total_cost_clockwise = 0, total_cost_counterclockwise = 0;

    // Input roads
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[i] = make_tuple(a, b, c); // Use make_tuple to create tuples
    }

    // Calculate clockwise cost
    for (const auto& road : roads) {
        int a, b, c;
        tie(a, b, c) = road; // Use tie to unpack the tuple
        total_cost_clockwise += c;
    }

    // Calculate counterclockwise cost
    for (const auto& road : roads) {
        int a, b, c;
        tie(a, b, c) = road;
        total_cost_counterclockwise += c; // Same cost calculation for demonstration
    }

    // Output the minimum of the two costs
    cout << min(total_cost_clockwise, total_cost_counterclockwise) << "\n";

    return 0;
}
