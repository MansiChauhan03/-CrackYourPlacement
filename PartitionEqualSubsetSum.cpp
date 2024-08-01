class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (sum % 2 != 0) {
            return 0;
        }
        int target = sum / 2;
        bool dp[target + 1] = {false};
        dp[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        return dp[target] ? 1 : 0;
    }
};
