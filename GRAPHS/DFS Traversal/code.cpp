void dfs(int node,vector<int> adj[],int visited[],vector<int>&dfsList){
      visited[node]=1;
      dfsList.push_back(node);
      
      for(auto it:adj[node]){
          if(!visited[it])
          dfs(it,adj,visited,dfsList);
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       int visited[V]={0};
       int startNode=0;
       vector<int>dfsList; //for storing dfs traversal of graph
       dfs(startNode,adj,visited,dfsList);
       return dfsList;
       
    }
