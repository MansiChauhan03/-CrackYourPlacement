SOLUTION 1:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        
        for(int i=0;i<nums.size();i++){
            if(count ==0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
****************************************************************************************************************************************************************************
SOLUTION 2:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     return major(nums,nums[0],0);
    }
    int major(vector<int>&nums,int val,int index){
        int c=0;
        for(int i=index;i<nums.size();i++){
            if(val==nums[i]){
                c++;
            }
            else{
                c--;
            }
            if(c<0){
                return major(nums,nums[i],i);
            }
        }
        return val;
    }
};
