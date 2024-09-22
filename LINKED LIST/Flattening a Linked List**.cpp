
class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root==NULL)return NULL;
        Node*leftHead=flatten(root->next);
        if(leftHead==NULL){
            return root;
        }
        //will reach this line when lastHead is not NULL
            //find the position in the curr main LL where left linked list is to be inserted;
            //solve using merge two sorted linkedList logic
            Node *dummyNode=new Node(-1);
            Node *temp=dummyNode;
            Node *curr1=root;
            Node *curr2=leftHead;
            while(curr1 && curr2){
                if(curr1->data<=curr2->data){
                    temp->bottom=curr1;
                    temp=temp->bottom;
                    curr1=curr1->bottom;
                }
                else{
                    temp->bottom=curr2;
                    temp=temp->bottom;
                    curr2=curr2->bottom;
                }
            }
            while(curr1){
               temp->bottom=curr1;
               temp=temp->bottom;
               curr1=curr1->bottom; 
            }
            
            while(curr2){
               temp->bottom=curr2;
               temp=temp->bottom;
               curr2=curr2->bottom; 
            }
            return dummyNode->bottom;
        
    }
