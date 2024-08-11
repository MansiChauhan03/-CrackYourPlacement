class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;
        int time = 0;

        // Count the number of fresh oranges and add rotten oranges to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    freshCount++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, and right
        int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // Check all adjacent cells
                for (int j = 0; j < 4; j++) {
                    int newX = x + directions[j][0];
                    int newY = y + directions[j][1];

                    // If the adjacent cell is fresh, mark it as rotten and add it to the queue
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        freshCount--;
                    }
                }
            }
            time++;
        }

        // If there are still fresh oranges left, return -1
        if (freshCount > 0) {
            return -1;
        }

        return time;
    }
};
