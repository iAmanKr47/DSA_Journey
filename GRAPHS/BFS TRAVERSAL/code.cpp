vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       int visited[V]={0};
       
       queue<int>q;
       q.push(0);
       visited[0]=1;
       vector<int>bfs;
       
       while(!q.empty()){
           int node =q.front();
           q.pop();
           bfs.push_back(node);
           
           for(auto it:adj[node]){
               if(!visited[it]){
                   visited[it]=1;    //visited is only mark as true when its getting added into queue
                   q.push(it);
               }
           }
           
       }
       return bfs;
       
    }
