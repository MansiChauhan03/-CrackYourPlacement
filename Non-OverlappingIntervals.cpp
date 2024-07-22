class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1]};
        }
        sort(a.begin(), a.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
            return x.second < y.second; 
        });
        int res = 0;
        int R = a[0].second;
        for(int i = 1; i < n; i++) {
            if(a[i].first < R) {
                res++;
            } else {
                R = a[i].second;
            }
        }
        return res;
    }
};
