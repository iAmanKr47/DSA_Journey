int count(struct Node* root){
      if(root==NULL)
      return 0;
      
      return 1+count(root->right)+count(root->left);
  }
  bool isCBT(struct Node* root,int index,int &cnt){
      if(root==NULL)
      return true;
      
      if(index>=cnt)
      return false;
      
      return isCBT(root->left,2*index+1,cnt)&&isCBT(root->right,2*index+2,cnt);
      
  }
  bool isMaxHeap(struct Node* root){
      //case 1 for leaf nodes 
     if(root->right==NULL&&root->left==NULL)
     return true;
     //case 2 only left child exist as it's a CBT
     if(root->right==NULL){
         return root->data>root->left->data;
     }
     //case 3 for nodes hving both left and right child
     else{
     return (root->data>root->left->data && root->data>root->right->data )&& isMaxHeap(root->left) && isMaxHeap(root->right);
     }
  }
  
    bool isHeap(struct Node* root) {
       int cnt=0;
       cnt=count(root);
       return isCBT(root,0,cnt)&&isMaxHeap(root);
    }
