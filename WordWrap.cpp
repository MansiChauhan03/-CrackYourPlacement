class Solution {
public:
    int solveWordWrap(vector<int> nums, int k) 
    { 
        int n = nums.size();
        
        // Step 1: Precompute extra spaces in each line if words[i] to words[j] are placed on a single line.
        vector<vector<int>> extra(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            extra[i][i] = k - nums[i];
            for (int j = i + 1; j < n; j++) {
                extra[i][j] = extra[i][j - 1] - nums[j] - 1;
            }
        }

        // Step 2: Compute the cost for placing words[i] to words[j] on one line.
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (extra[i][j] < 0) {
                    cost[i][j] = INT_MAX;  // Impossible to place these words on one line
                } else if (j == n - 1 && extra[i][j] >= 0) {
                    cost[i][j] = 0;  // No extra space cost for the last line
                } else {
                    cost[i][j] = extra[i][j] * extra[i][j];
                }
            }
        }

        // Step 3: Use dynamic programming to find the minimum total cost.
        vector<int> dp(n, INT_MAX);
        vector<int> p(n, 0);  // Auxiliary array to reconstruct the solution

        dp[0] = cost[0][0];
        for (int j = 1; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (dp[i-1] != INT_MAX && cost[i][j] != INT_MAX && dp[j] > dp[i-1] + cost[i][j]) {
                    dp[j] = dp[i-1] + cost[i][j];
                    p[j] = i;
                }
            }
        }

        return dp[n-1];
    }
};
