class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> memo(n + 1, -2);
        return maximizeTheCutsHelper(n, x, y, z, memo);
    }

    int maximizeTheCutsHelper(int n, int x, int y, int z, vector<int>& memo)
    {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            return -1;
        }
        if (memo[n] != -2) {
            return memo[n];
        }
        int cuts_x = maximizeTheCutsHelper(n - x, x, y, z, memo);
        int cuts_y = maximizeTheCutsHelper(n - y, x, y, z, memo);
        int cuts_z = maximizeTheCutsHelper(n - z, x, y, z, memo);

        int maxCuts = max(max(cuts_x, cuts_y), cuts_z);
        if (maxCuts == -1) {
            memo[n] = -1;
        } else {
            memo[n] = maxCuts + 1;
        }
        return memo[n];
    }

};
