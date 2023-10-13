class Solution
{ 
    
    public:
    void traversal(Node *root1, Node *root2,vector<int>&ans){
        if(root1==NULL)
        return ;
        
        traversal(root1->left,root2,ans);

        bool isPresent=findNode(root2,root1->data);
        
        if(isPresent){
        ans.push_back(root1->data);
        }
        
        traversal(root1->right,root2,ans);
    }
    bool findNode(Node *root2, int &target){
        if(root2==NULL)
        return false;
        
        if(target==root2->data)
        return true;
        
        if(target>root2->data)
        return findNode(root2->right,target);
        
        if(target<root2->data)
        return findNode(root2->left,target);
         
    }
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     vector<int>ans;
     traversal(root1,root2,ans);
     return ans;
    }
};
