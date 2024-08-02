class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // Create a map to store the adjacency list
        unordered_map<int, vector<int>> adj;
        for (const auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        // Find the start element, which has only one adjacent element
        int start;
        for (const auto& [key, value] : adj) {
            if (value.size() == 1) {
                start = key;
                break;
            }
        }

        // Restore the array using the adjacency list
        vector<int> result;
        unordered_set<int> visited;
        result.push_back(start);
        visited.insert(start);

        while (result.size() < adjacentPairs.size() + 1) {
            int last = result.back();
            for (int neighbor : adj[last]) {
                if (visited.find(neighbor) == visited.end()) {
                    result.push_back(neighbor);
                    visited.insert(neighbor);
                    break;
                }
            }
        }

        return result;
    }
};
