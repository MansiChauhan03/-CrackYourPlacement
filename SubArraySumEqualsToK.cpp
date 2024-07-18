SOLUTION 1:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int c=0;
     int n=nums.size();
     for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s+=nums[j];
            if(s==k){
                c++;
            }
        }
     } 
     return c; 
    }
};

****************************************************************************************************************************************************************************
SOLUTION 2:
  
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i] = nums[i] + pre[i-1];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(pre[i]==k) ans++;
            if(mp.find(pre[i]-k)!=mp.end()){
                ans += mp[pre[i]-k];
            }
            mp[pre[i]]++;
        }
        return ans;
    }
};
