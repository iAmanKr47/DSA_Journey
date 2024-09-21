class Solution
{
public:

//at each node we have to attach left linked list tail to root and root node  to right LL
    Node *flattenBST(Node *root)
    {
        if(root==NULL)return NULL;
        
        Node*leftHead=flattenBST(root->left);//trust a LL is formed at left
        Node*rightHead=flattenBST(root->right);//truest a LL is formed at right //now  you have head of both LL
        root->left=NULL;//left pointer should be NULL as per question 
        
        //now find  left linked list tailNode and link it's right with root node
        
        if(leftHead==NULL){//edge case when left linked list not present then the rootNode is the leftHead else follow above logic
            leftHead=root;
        }
        
        else{//FINDING TAIL
            Node*tail=leftHead;
            while(tail && tail->right){
              tail=tail->right;
            }
            tail->right=root; //LEFT LL IS ATTACHED TO ROOT
        }
        
        root->right=rightHead;//ATTTACH ROOT AND RIGHT LL
        return leftHead;
    }
};
