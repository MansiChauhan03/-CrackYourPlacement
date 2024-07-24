class Solution {
  public:
    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& s, const vector<int> adj[]) {
    visited[v] = true;
    s[v] = true;
    for (int i : adj[v]) {
        if (!visited[i] && isCyclicUtil(i, visited,s, adj)) {
            return true;
        }
        else if (s[i]) {
            return true;
        }
    }
    s[v] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> s(V, false);
    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            if (isCyclicUtil(u, visited, s, adj)) {
                return true;
            }
        }
    }
    return false;
}

};
