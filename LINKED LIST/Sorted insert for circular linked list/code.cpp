Node *sortedInsert(Node* head, int data)
    {
        if (head == NULL) {
           Node* node = new Node(data);
           node->next = node;
           
           return node;
        }

        Node* newNode = new Node(data);
         
        if(head->data >= data ){
         newNode->next=head;
        
          Node *curr = head;
            while(curr->next != head){
                curr = curr->next; 
            }
            curr -> next = newNode;
            
         return newNode;
        }
        
       Node *front = head->next;
       Node *rear  = head;
       while( front!=head){
           if( front->data>data ) break;
           rear=front;
           front=front->next;
       }
       
        rear->next=newNode;
        newNode->next=front;
        
        return head;
    }
