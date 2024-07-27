class Solution {
public:
    int N; 
    int answer;
    vector<bool> visited;
    unordered_map<int, vector<int>> validMatches; 
    
    int countArrangement(int N) {
        this->N = N;
        answer = 0;
        visited.resize(N + 1, false);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i % j == 0 || j % i == 0) {
                    validMatches[i].push_back(j);
                }
            }
        }
        depthFirstSearch(1);
        return answer;
    }

    void depthFirstSearch(int index) {
        if (index == N + 1) {
            ++answer;
            return;
        }

        for (int num : validMatches[index]) {
            if (!visited[num]) {
                visited[num] = true;
                depthFirstSearch(index + 1);
                visited[num] = false; 
            }
        }
    }
};
