class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int rows, int cols, int source) {
        
        if (sr < 0 || sr >= rows || sc < 0 || sc >= cols || image[sr][sc] != source) {
            return;
        }

        image[sr][sc] = newColor;

        // Perform DFS in all four directions
        dfs(image, sr - 1, sc, newColor, rows, cols, source); // top
        dfs(image, sr + 1, sc, newColor, rows, cols, source); // down
        dfs(image, sr, sc - 1, newColor, rows, cols, source); // left
        dfs(image, sr, sc + 1, newColor, rows, cols, source); // right
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) {
            return image;
        }

        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc];
        dfs(image, sr, sc, color, rows, cols, source);

        return image;
    }
};
