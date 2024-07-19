SOLUTION 1------------->

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    bool shouldFillFirstRow = false;
    bool shouldFillFirstCol = false;

    for (int j = 0; j < n; ++j)
      if (matrix[0][j] == 0) {
        shouldFillFirstRow = true;
        break;
      }

    for (int i = 0; i < m; ++i)
      if (matrix[i][0] == 0) {
        shouldFillFirstCol = true;
        break;
      }

    // Store the information in the first row and the first column.
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }

    // Fill 0s for the matrix except the first row and the first column.
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;

    // Fill 0s for the first row if needed.
    if (shouldFillFirstRow)
      for (int j = 0; j < n; ++j)
        matrix[0][j] = 0;

    // Fill 0s for the first column if needed.
    if (shouldFillFirstCol)
      for (int i = 0; i < m; ++i)
        matrix[i][0] = 0;
  }
};



SOLUTION 2-------------->

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return;
        vector<int>colsWithZero;
        vector<int>rowsWithZero;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(matrix[i][j]==0){
                    rowsWithZero.push_back(i);
                    colsWithZero.push_back(j);
                }
            }
        }

        for(auto x : rowsWithZero){

            for(int i = 0 ; i < cols ; i++)matrix[x][i] = 0;
        }
        for(auto x : colsWithZero){

            for(int i = 0 ; i < rows ; i++)matrix[i][x] = 0;
        }
        
    }
};
