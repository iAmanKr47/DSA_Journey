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


//code 2:

class Solution
{
public:
    int maxSum=0;
    int maxLevel=0;
    void solve(Node *root,int level,int sum){
        if(root == NULL) return;
        
        //check at the leaf node
        if(root->left==NULL && root->right==NULL){
            sum+=root->data;
            if(level>maxLevel) {
                maxLevel=level;
                maxSum=sum;
            }
            else if(level==maxLevel) maxSum=max(maxSum,sum);
            
            return ;
        }
      
        solve(root->left,level+1,sum+root->data);
        solve(root->right,level+1,sum+root->data);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {   if(root->right==NULL && root->left==NULL ) return root->data; 
        int level=0;
        int sum=0;
        solve(root,level,sum);
        return maxSum;
    }
};
