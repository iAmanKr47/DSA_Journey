int floor(Node* root, int x) {
 int floorVal=-1;
   Node *temp=root;
   while(temp!=NULL){
        if(temp->data<=x){
        floorVal=temp->data;
        temp=temp->right;
        }
        else
        temp=temp->left;
   }
   return floorVal;
}
