SOLUTION 1:
 
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++ans;
        }

    return ans;
  }

 private:
  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] != '1')
      return;

    grid[i][j] = '2';  // Mark '2' as visited.
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
};


SOLUTION 2:
 
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || vis[row][col] || grid[row][col] == '0') return;

        vis[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[]  = {0, -1, 0, 1};
        for(int i = 0;  i<4; i++){
            dfs(row+delRow[i], col+delCol[i], grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};
