Node* reverseDLL(Node * head)
    {
       Node*prev=NULL;
       Node*curr=head;
       if(head==NULL||head->next==NULL)
       return head;
       while(curr!=NULL){ //swapping of prev and next links of the DLL
           prev=curr->prev;
           curr->prev=curr->next;
           curr->next=prev;
           curr=curr->prev;
       }
       return prev->prev;
    }
