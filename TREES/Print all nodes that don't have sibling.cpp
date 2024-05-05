/*Intuition
/The idea is to simply traverse the tree and add such data that have no siblings that is all the left nodes which have no right nodes 
and all right nodes which have no left nodes.*/

void solve(Node* node,vector<int>&ans){
    if(node==NULL)return;
    if(!node->left && node->right){
        ans.push_back(node->right->data);
    }
    else if(node->left && !node->right){
         ans.push_back(node->left->data);
    }
    solve(node->left,ans);
    solve(node->right,ans);
}
vector<int> noSibling(Node* node)
{
    vector<int>ans;
    solve(node,ans);
    sort(ans.begin(),ans.end());
    if(ans.size()==0)return {-1};
    return ans;
}
