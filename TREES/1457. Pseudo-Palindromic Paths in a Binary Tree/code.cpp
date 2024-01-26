class Solution {
public:
int cnt=0;

void traversal(TreeNode* root,vector<int>&mp)
{
if(root==NULL) return;

mp[root->val]++;

if(root->left==NULL&&root->right==NULL){
    
    int freq=0;
    for(auto i:mp)if(i%2!=0)freq++;
    if(freq<=1) cnt++;
    mp[root->val]--;
    return;
}

 traversal(root->left,mp);
 traversal(root->right,mp);
  mp[root->val]--;
}
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>mp(10,0);
        traversal(root,mp);
        return cnt;
    }
}; 
