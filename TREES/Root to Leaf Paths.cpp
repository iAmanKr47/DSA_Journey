//code 1:use recurrsion
void dfs(Node*root,vector<int>currPath,vector<vector<int>>&ans){
       if(root==NULL)return;
       if(!root->left &&!root->right){
           currPath.push_back(root->data);
           ans.push_back(currPath);
           
           return;
       }
       currPath.push_back(root->data);
       dfs(root->left,currPath,ans);
       dfs(root->right,currPath,ans);
        
   }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>currPath;
        dfs(root,currPath,ans);
        return ans;
    }


//code 2: backtracking
void dfs(Node*root,vector<int>&currPath,vector<vector<int>>&ans){
       if(root==NULL)return;
       if(!root->left &&!root->right){
           currPath.push_back(root->data);
           ans.push_back(currPath);
           currPath.pop_back();
           return;
       }
       currPath.push_back(root->data);
       dfs(root->left,currPath,ans);
       dfs(root->right,currPath,ans);
        currPath.pop_back();
   }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>currPath;
        dfs(root,currPath,ans);
        return ans;
    }

