class Solution
{
	public:
	void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<int> adj[]) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }
    Stack.push(v);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> Stack;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    vector<int> topo_order;
    while (!Stack.empty()) {
        topo_order.push_back(Stack.top());
        Stack.pop();
    }

    return topo_order;
}
};
