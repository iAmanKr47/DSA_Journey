void solve(Node *root,int sum,int &maxSum,int len,int&maxLen){
        //base case reched as we reached leaf node
         if( root == NULL ) {
            return;
        }
        sum=sum+root->data;
        
        if(len>= maxLen){
            maxLen = len;
            maxSum = sum;
        }
        
        solve(root->left,sum,maxSum,len+1,maxLen);
        solve(root->right,sum,maxSum,len+1,maxLen);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum=0;
        int maxSum=INT_MIN;
        int len=0;
        int maxLen=0;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
    }
};
