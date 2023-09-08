 void solve(Node *root, int &K,int&ans){
        if(root==NULL)
        return;
        //go in extreme right first
        solve(root->right,K,ans);
        
        //while returning decrement K BY 1
        K--;
        //check for ans if k==0
        if(K==0)
        {
            ans=root->data;
            return;
        }
        // if right se ans nhi mila then go to left
        solve(root->left,K,ans);
    }
        
    
    int kthLargest(Node *root, int K)
    {
        int ans;
        solve(root,K,ans);
        return ans;
    }
