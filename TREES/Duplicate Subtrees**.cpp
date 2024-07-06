//store the subtree in map and if that subtree is seen more than once in the tree include the root node od that subtree in your ans
//store subtree in string of form  LEFTSUBTREE#NODE#RIGHTSUBTREE ,i.e use separator 

string inorder(Node*root,unordered_map<string,int>&mp,vector<Node*>&ans){
      if(root==NULL)return "";
      
      string subtree="";
      
      string left=inorder(root->left,mp,ans);
      subtree+=left+"#"+to_string(root->data);
      string right=inorder(root->right,mp,ans);
      subtree+="#"+right;
      
      if(mp.find(subtree)!=mp.end() && mp[subtree]==1)ans.push_back(root);
      mp[subtree]++;
      return subtree;
  }
    vector<Node*> printAllDups(Node* root) {
        vector<Node*>ans;
        unordered_map<string,int>mp;
        //store the subtree of form leftSubtre#Node#RightSubtree
        auto tree=inorder(root,mp,ans);
        return ans;
    }
