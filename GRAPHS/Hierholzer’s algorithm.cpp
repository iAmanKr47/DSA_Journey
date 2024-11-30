//2097. Valid Arrangement of Pairs
//refer MIK
class Solution {
public:
void dfs(unordered_map<int,vector<int>>&adj,vector<int>&eulerianPath,int &startNode){
    stack<int>st;
    st.push(startNode);
    while(st.size()>0){
        auto top=st.top();
        
        if(!adj[top].empty()){
              st.push(adj[top].back());
              adj[top].pop_back();//main step
              
        }
        else{
             eulerianPath.push_back(top);
             st.pop();//pop as we have reached at the end of the particular path 
        }
    }
}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>outdegree;
        unordered_map<int,int>indegree;
        //create graph using adjancy list
        //indegree and outdegree of every node
        for(auto p: pairs){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        
        //select the valid starting node from the graph
        //starting node is that node where ( outdegree[x] - indegree[x]==1 )
        int startNode=pairs[0][0];
        for(auto i: adj){
            int node=i.first;
            if(outdegree[node]- indegree[node]==1){
                startNode=node;
                break;
            }
        }

        //now perfrom dfs search 
        vector<int>eulerianPath;
        dfs(adj,eulerianPath,startNode);
        //now eulerianPath is having path from end to start 
        //so reverse it
        reverse(eulerianPath.begin(),eulerianPath.end());
        vector<vector<int>>result;
        for(int i=0;i<eulerianPath.size()-1;i++){
            result.push_back({eulerianPath[i],eulerianPath[i+1]});
        }
         return result;
    }
};
