#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
char labyrinth[MAX][MAX];        // Store the labyrinth
bool visited[MAX][MAX];          // Track visited positions
pair<int, int> parent[MAX][MAX]; // Track the parent of each cell (for path reconstruction)
int n, m;                        // Dimensions of the labyrinth
pair<int, int> start, endPos;    // Coordinates of 'A' (start) and 'B' (end)

// Directions: {down, up, right, left}
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char dir[] = { 'D', 'U', 'R', 'L' }; // Directions corresponding to movements

bool is_valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y]);
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;

        q.pop();

        // If we reach the end, stop the search
        if (make_pair(x, y) == endPos) return;

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = { x, y }; // Record where we came from
                q.push({ nx, ny });
            }
        }
    }
}

string reconstruct_path() {
    string path;
    pair<int, int> current = endPos;

    // Backtrack from 'B' to 'A' using the parent array
    while (current != start) {
        pair<int, int> prev = parent[current.first][current.second];
        for (int i = 0; i < 4; i++) {
            if (prev.first + dx[i] == current.first && prev.second + dy[i] == current.second) {
                path += dir[i];
                break;
            }
        }
        current = prev;
    }

    reverse(path.begin(), path.end()); // Reverse to get the path from A to B
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') start = { i, j };
            if (labyrinth[i][j] == 'B') endPos = { i, j }; // Changed variable name here
        }
    }

    // Perform BFS to find the shortest path
    bfs();

    // If the end 'B' is visited, then a path exists
    if (visited[endPos.first][endPos.second]) {
        cout << "YES\n";
        string path = reconstruct_path();
        cout << path.length() << "\n";
        cout << path << "\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
