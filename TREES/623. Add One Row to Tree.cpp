//simple tree dfs traversal

void solve(TreeNode* root,int &val,int depth){
    if(root==NULL) return ;
    if( depth-1==0){
        TreeNode* leftPart=root->left;
        TreeNode* rightPart=root->right;
       
       
           if(leftPart){
           TreeNode *tempLeft=new TreeNode(val);
           root->left=tempLeft;
           tempLeft->left=leftPart;
           
           }
         if(rightPart){
           TreeNode *tempRight=new TreeNode(val);
            root->right=tempRight;
            tempRight->right=rightPart;
            
         }
        return ;
    }
     if(root->left)solve(root->left,val,depth-1);
     if(root->right)solve(root->right,val,depth-1);
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if(depth==1){
           TreeNode *newHead=new TreeNode(val);
           newHead->left=root;
           return newHead;
         }
         solve(root,val,depth);
         return root;
    }
