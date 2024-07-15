class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                swap(nums[i],nums[ind]);
                ind++;
            }
        }
        for(int i = ind; i<n; i++){
            if(nums[i]==1){
                swap(nums[i],nums[ind]);
                ind++;
            }
        }
    }
};
