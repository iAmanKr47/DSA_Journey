        Node* insert(Node* node, int data) {
        
            Node * currNode=node;
            
            while(true){
                 if(currNode->data==data)
                {
                     break;
                }
                 else if(currNode->data<data){
                     
                     if(currNode->right!=NULL)
                     currNode=currNode->right;
                     else
                     {
                         Node* newnode = new Node(data);
                         currNode->right=newnode;
                         break;
                     }
                 }
                 else if(currNode->data>data){
                     
                  if(currNode->left!=NULL)
                     currNode=currNode->left;
                     else
                     {
                         Node* newnode = new Node(data);
                         currNode->left=newnode;
                         break;
                     }
                 } 
            }
            return node;
    }
