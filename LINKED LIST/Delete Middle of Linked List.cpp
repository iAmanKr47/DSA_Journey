
Node* deleteMid(Node* head)
    {
        if(head->next==NULL)return NULL;
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
      //tortoise hare algo
        Node *prev=NULL;
        Node *slow=head;
        Node *fast=head;
        while(fast->next &&fast->next->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        //case of odd length LL: prev would be pointing one node behind the node which is need to be deleted
        if(fast->next==NULL){
            Node*delNode=prev->next;
            prev->next=prev->next->next;
            free(delNode);
            return head;
        }
        //case of even length LL when fast->next->next==NULL : slow pointer would be pointing one node behind the node which is need to be deleted
            Node*delNode=slow->next;
            slow->next=slow->next->next;
            free(delNode);
        
        return head;
    }
