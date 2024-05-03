class Solution {
public:
    void dfs(TreeNode*root,int maxi,int &cnt){
        if(root==NULL){
            return ;
        }
        if(root->val>=maxi){
            cnt++;
            maxi=root->val;
        }
        dfs(root->left,maxi,cnt);
        dfs(root->right,maxi,cnt);

    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        int cnt=0;
        dfs(root,maxi,cnt);
        return cnt;
    }
};
