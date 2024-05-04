class Solution
{
    public:
    void solve(Node* root,vector<int>&preorder){
        if(root==NULL){
            preorder.push_back(-1);
            return ;
        }
        preorder.push_back(root->data);
        solve(root->left,preorder);
        solve(root->right,preorder);
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int>preorder;
        solve(root,preorder);
        return preorder;
    }
    
    //Function to deserialize a list and construct the tree.
    int index=0;
    Node * deSerialize(vector<int> &A)
    {
       if(A[index]==-1){
           index++;
           return NULL;
       }
       Node*root=new Node(A[index++]);
       root->left=deSerialize(A);
       root->right=deSerialize(A);
       
       return root;
    }

};
