//LOGIC: If a node is previously been visited and that's not a parent then a cycle would be definitely present
//DFS TRAVERSAL
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int visited[26]={0};
        map<int,vector<int>> mp;
        for(int i=0;i<points.size();i++){
            int key = max(abs(points[i][0]),abs(points[i][1])); 
            mp[key].push_back(i);
        }
        
        int ans = 0;
        for(auto& i:mp){
            for(auto& j:i.second){
                int chr = s[j]-'a';
                if(visited[chr]>0)
                    return ans;
                visited[chr]=1;
            }
            ans += i.second.size();
        }
        
        return ans;
    }
};



//BFS TRAVERSAL

class Solution {
  public:
  bool bfsIsCycle(int node,vector<int> adj[],int visited[]){
      queue<pair<int,int>>q;//node and it's parent
      q.push({node,-1});
      visited[node]=1;
      
      while(!q.empty()){
          auto front=q.front();
          int currNode=front.first;
          int parent=front.second;
          q.pop();
          for(auto neighbour:adj[currNode]){
             
               if(visited[neighbour]==0){
                  q.push({neighbour,currNode});
                    visited[neighbour]=1;
              }
              else  if(neighbour!=parent )return true;
            }
       }
       return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        int visited[v]={0};
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                if(bfsIsCycle(i,adj,visited)) return true;
            }
        }
        return false;
    }
};
