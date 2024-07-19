class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int m = (low + high) / 2;
            if (nums[m] == target) {
                return m;
            }
            
            // Check if the left half is sorted
            if (nums[low] <= nums[m]) {
                // If target is in the left half
                if (nums[low] <= target && target < nums[m]) {
                    high = m - 1;
                } else {
                    low = m + 1;
                }
            } else { // Otherwise, the right half is sorted
                // If target is in the right half
                if (nums[m] < target && target <= nums[high]) {
                    low = m + 1;
                } else {
                    high = m - 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};
