int maxVal(Node *root){
    if(root==NULL)
    return -1;
 Node *pred=root;
    while(pred->right!=NULL){
        pred=pred->right;
    }
    return pred->data;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
   if(root==NULL)
   return NULL;
   
   //serach for target node(X) 
   
   if(root->data<X){
       //then go to right subtree 
        root->right=deleteNode(root->right,X);
    }
    else if(root->data>X){
        //then go to left subtree
        root->left=deleteNode(root->left,X);
    }
    
   else{ //when found target node then 
      
       //4 cases would be there 
       
       //case 1 No child i,e leaf node 
       if(root->left==NULL&&root->right==NULL){
         
           return NULL;
       }
       //case 2 left child exist
       else if(root->left!=NULL&&root->right==NULL){
           return root->left;
       }
       //cases3 right child exist
       else if(root->left==NULL&&root->right!=NULL){
           return root->right;
       }
       //case 4 both child exist
       else{
           int predecessor= maxVal(root->left);
           root->data=predecessor;
           root->left=deleteNode(root->left,predecessor);
           //return root;
       }
   }
   return root;
}
