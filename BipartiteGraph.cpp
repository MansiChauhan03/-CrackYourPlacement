class Solution {
public:

    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1); 
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { 
                if (!bipartiteBFS(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool bipartiteBFS(int src, vector<int> adj[], vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0; 
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) { 
                    color[v] = 1 - color[u]; 
                    q.push(v);
                } else if (color[v] == color[u]) { 
                    return false;
                }
            }
        }
        return true;
    }

};
