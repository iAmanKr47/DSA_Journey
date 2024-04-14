void solve(TreeNode* root,int &sum){
        if(root==NULL) return ;
        if(root->left && !root->left->left && !root->left->right)
         sum += root->left->val;
        solve(root->left,sum);   
        solve(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL || root->left==NULL &&!root->right) return 0;
        int sum=0;
        solve(root,sum);
        return sum;
    }
