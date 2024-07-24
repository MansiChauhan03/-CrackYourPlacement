class Solution {
  public:
   bool isCyclicUtil(int v, vector<bool>& visited, int parent, const vector<int> adj[]) {
    visited[v] = true;

    for (int i : adj[v]) {
       
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, v, adj)) {
                return true;
            }
        }
        
        else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            if (isCyclicUtil(u, visited, -1, adj)) {
                return true;
            }
        }
    }
    return false;
}
};
