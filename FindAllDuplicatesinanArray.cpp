SOLUTION 1------------>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};


****************************************************************************************************************************************************************************
SOLUTION 2------------>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0)
                answer.push_back(abs(nums[i]));
            else {
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
            }
        }
        return answer;
    }
};
