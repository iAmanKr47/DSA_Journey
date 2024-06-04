//perform dfs and when all the neighbours of current node is visited then push it into stack
//at the end of all dfs calls stack would be left with elemnts in topological order


//code 1: USING DFS
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




//code 2: USING KAHN'S ALGORITHM
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void bfs(vector<int> adj[],queue<int>&q,vector<int>&indegree,vector<int>&topoSort){
	    while(q.size()>0){
	        auto front=q.front();
	        q.pop();
	        topoSort.push_back(front);
	  //decrease indegree of all ihe neighbour of front node
	  //and if indegree of any of its neighbour becomes zero in this process then push it into the queue
	  //the previous step is done as when its indegree is zero now that node is safe to be the ans as it has no dependencies with any other node
	      
	        for(auto neighbour:adj[front]){
	            indegree[neighbour]--;
	            if(indegree[neighbour]==0)q.push(neighbour);
	        }
	    }
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    queue<int>q;//to perform bfs traversal and in entire bfs traversal store only vertices whose indegree is zero. 
	    vector<int>topoSort;
	    //fill indegree of all vertices
	    for(int i=0;i<V;i++){
	        for(auto neighbour:adj[i]) indegree[neighbour]++;
	    }
	    //now push those vertices whose indegree are 0
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    //now perform bfs
	    bfs(adj,q,indegree,topoSort);
	    
	    return topoSort;
	}
};

