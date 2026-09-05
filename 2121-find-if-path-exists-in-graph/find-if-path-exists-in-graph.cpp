class Solution {
public:
vector<bool>visited;
bool dfs(int node,int destination,vector<vector<int>>& graph){
    visited[node]=true;
    if(node==destination) return true;
    for(int neighbour:graph[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour,destination, graph)){
                return true;
            }
        }
    }
        return false;
    
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     vector<vector<int>>graph(n);
     for(auto edge:edges) {
        int u=edge[0];
        int v=edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
     }  
     visited.resize(n,false);
     return dfs(source, destination, graph);
    }


};