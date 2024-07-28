SOLUTION:1

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++){
            string temp = strs[i];

            sort(begin(temp), end(temp));

            mp[temp].push_back(strs[i]);
        }

        for(auto& it: mp){
            result.push_back(it.second);
        }

        return result;
    }
};

SOLUTION:2

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (auto& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            d[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : d) ans.emplace_back(v);
        return ans;
    }
};
