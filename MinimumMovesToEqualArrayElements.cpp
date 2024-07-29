SOLUTION 1:
  
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int steps=0;
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        int median=nums[n/2];
        for(int i=0;i<n;i++){
            steps+=abs(nums[i]-median);
        }

        return steps;
    }
};

SOLUTION 2:

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums[nums.size() >> 1];
        int ans = 0;
        for (int& v : nums) ans += abs(v - k);
        return ans;
    }
};
