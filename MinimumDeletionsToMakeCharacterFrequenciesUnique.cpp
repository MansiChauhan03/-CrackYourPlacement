class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int deletions = 0;
        for (int i = 1; i < 26; ++i) {
            if (freq[i] == 0) break;  
            while (freq[i] && freq[i] >= freq[i - 1]) {
                freq[i]--;
                deletions++;
            }
        }
        
        return deletions;
    }
};
