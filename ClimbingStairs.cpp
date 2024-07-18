class Solution {
    public int climbStairs(int n) {
        if (n <= 1) {
            return n; // Base case: 0 steps (0 ways), 1 step (1 way)
        }

        int[] dp = new int[n + 1]; // Array to store the number of ways for each step
        dp[1] = 1; // One way to reach step 1
        dp[2] = 2; // Two ways to reach step 2 (1+1 or 2)

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; // Ways for current step = ways for previous two steps
        }

        return dp[n]; // Number of ways to reach the top (nth step)
    }
}
