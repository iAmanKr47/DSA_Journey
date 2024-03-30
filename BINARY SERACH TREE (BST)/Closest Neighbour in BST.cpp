//approach 1
class Solution {
  public:
  void solve(Node* root,int&n,int &maxi){
      if(root==NULL)return;
      
      if(root->key<=n){
          maxi=max(maxi,root->key);
          if(root->key==n)return;//if root->data==n then no need to check further so return ;
          solve(root->right,n,maxi);
      }
      else{
          solve(root->left,n,maxi);
      }
  }
    int findMaxForN(Node* root, int n) {
     
      int maxi=-1;
      solve(root,n,maxi);
      return maxi;
    }
};


//approach 2
 int findMaxForN(Node* root, int n) {
          int num=-1;
        while(root!=NULL){
            if(root->key<=n){
                num=root->key;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return num;
    }
