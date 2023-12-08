void preorder(TreeNode* root,string& ans){
    if(!root->left && !root->right) {
        ans+=to_string(root->val);
        return;
    }
    ans+=to_string(root->val);
    
    if(root->left){
        ans+='(';
       preorder(root->left,ans);
        ans+=')';
    }
    if(root->right)
    {
     if (!root->left) ans+="()";
     ans+='(';
     preorder(root->right,ans);
     ans+=')';
    }
}
    string tree2str(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }
