
class Solution {
  public:
  bool checkIsSumTree=true;
  int dfs(Node*root){
      if(root==NULL)return 0;
      if(root->left==NULL && root->right==NULL)return root->data;
      
      int leftSum=dfs(root->left);
      int rightSum=dfs(root->right);
      
      if(root->data!=leftSum+rightSum)checkIsSumTree=false;
      return root->data+leftSum+rightSum;
  }
    bool isSumTree(Node* root) {
        int sum=dfs(root);
        return checkIsSumTree;
    }
};
