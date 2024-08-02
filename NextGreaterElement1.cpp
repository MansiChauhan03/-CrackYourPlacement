class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        // Process nums2 to find the next greater element for each number
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // For the remaining elements in the stack, there is no next greater element
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        // Prepare the result for nums1 based on the next greater elements found in nums2
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};
