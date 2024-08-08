class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> map;
        for (const auto& str : string_list) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }
};
