class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        
        // Collect all edges from the adjacency list
        for (int u = 0; u < V; u++) {
            for (const auto& edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];
                edges.push_back({weight, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int mstWeight = 0;
        int edgeCount = 0;
        for (const auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (findParent(u, parent)!= findParent(v, parent)) {
                unionNodes(u, v, parent, rank);
                mstWeight += weight;
                edgeCount++;
                if (edgeCount == V - 1) break;
            }
        }

        return mstWeight;
    }

    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};
