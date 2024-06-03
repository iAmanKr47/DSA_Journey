//perform dfs and when all the neighbours of current node is visited then push it into stack
//at the end of all dfs calls stack would be left with elemnts in topological order

class Solution
{
	public:
	void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int>&st){
	    vis[node]=1;
	    
	    for(auto neighbour:adj[node]){
	        if(!vis[neighbour])dfs(neighbour,adj,vis,st);
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int>topSort;
	    while(!st.empty()){
	        int top=st.top();
	        st.pop();
	        topSort.push_back(top);
	    }
	    return topSort;
	}
};
