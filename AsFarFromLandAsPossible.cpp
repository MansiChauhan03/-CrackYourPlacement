class Solution {
public:
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // Initialize the queue with all land cells and mark them as visited
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        // If there are no water cells or no land cells, return -1
        if (q.size() == n * n || q.empty()) return -1;

        int distance = -1;

        // Perform BFS
        while (!q.empty()) {
            int qSize = q.size();
            ++distance;
            while (qSize--) {
                pair<int, int> landCell = q.front();
                q.pop();
                for (auto dir : directions) {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;

                    if (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0) {
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return distance;
    }
};
