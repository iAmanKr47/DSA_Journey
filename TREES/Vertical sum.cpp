 // use concept of number line.
class Solution{
  public:
    map<int,int>mp;
    void solve(Node* root,int xAxisVal){
        if(root==NULL) return;
        mp[xAxisVal]+=root->data;
        solve(root->left,xAxisVal-1);
        solve(root->right,xAxisVal+1);
    }
    vector <int> verticalSum(Node *root) {
        vector<int>ans;
        solve(root,0);
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
