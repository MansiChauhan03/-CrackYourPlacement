class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int>&visited,vector<int>& dfs_order,vector<int>adj[]){
        visited[node]=true;
        dfs_order.push_back(node);
        
        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,dfs_order,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>dfs_order;
        vector<int> visited(V,false);
        
        dfs(0,visited,dfs_order,adj);
        
        return dfs_order;
    }
};
