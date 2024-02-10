APPROACH 1:

    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(root==NULL)return 1;
     if(root->left==NULL&& root->right==NULL) return 1;
     int ans=0;
     if(root->left) ans+=root->left->data;
     if(root->right) ans+=root->right->data;
     if(ans!=root->data) return 0;
     
     return isSumProperty(root->left)&&isSumProperty(root->right);
     
    }

APPROACH 2:

int isSumProperty(Node *root)
    {
     if(root==NULL) return 1;
     
        int sum=0;
        if(root->left!=NULL){
            sum +=root->left->data;
        }
        
        if(root->right!=NULL){
            sum+=root->right->data;
        }
        
        if(sum!=root->data && sum!=0){
            return 0;
        }
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    
    }

APPROACH 3:

 int isSumProperty(Node *root)
    {
    queue<Node*>q;
    q.push(root);
    while(q.size()!=0){
       Node *front=q.front();
        q.pop();
        int sum=0;
        if(front->left){
            sum+=front->left->data;
            q.push(front->left);
        }
        if(front->right){
            sum+=front->right->data;
            q.push(front->right);
        }
        if(sum!=0 && sum!=front->data)
        return 0;
        
    }
    return 1;
    }

