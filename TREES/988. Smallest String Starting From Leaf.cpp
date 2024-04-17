void solve(TreeNode* root,string curr,string &ans){
    if(root==NULL)return ;
    if(root->left==NULL &&root->right==NULL){
        curr+=char(root->val+'a');
        reverse(curr.begin(),curr.end());
      if(ans=="" || curr<ans ){
        ans=curr;
     }
     return ;
    }
    solve(root->left,curr+char('a' + root->val),ans);
    solve(root->right,curr+char('a' +root->val),ans);

}
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        string ans="";
        if(!root->left && !root->right) return ans+char(root->val+'a');
        solve(root,curr,ans);
        return ans;
    }
