class Solution {
public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        bool visited[n] = {false};
        return backtrack(a, visited, target, k, 0, 0, n);
    }

private:
    static bool backtrack(int a[], bool visited[], int target, int k, int start, int currentSum, int n)
    {
        if (k == 0) {
            return true;
        }
        if (currentSum == target) {
            return backtrack(a, visited, target, k - 1, 0, 0, n);
        }
        for (int i = start; i < n; i++) {
            if (!visited[i] && currentSum + a[i] <= target) {
                visited[i] = true;
                if (backtrack(a, visited, target, k, i + 1, currentSum + a[i], n)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};
