 void flatten(Node *root)
    {
       Node * curr=root;
       
       while(curr!=NULL){ 
           //if curr->left exist 
           if(curr->left){
               Node *pred=curr->left;
              //go to  extreme right of left part of curr node and name it that node predecessor(pred)
               while(pred->right!=NULL){
                   pred=pred->right;
               }
               //now first points pred->right to curr ke right part se and then curr ka right to curr->left
               //after processing each currr node we have to make its left pointer points to null
               
               pred->right=curr->right;
               curr->right=curr->left;
               curr->left=NULL;
           }
           curr=curr->right; //now move right
       }
    }
