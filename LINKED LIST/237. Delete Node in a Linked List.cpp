//JUST COPY NEXT NODE'S VALUE TO THE CURRENT NODE 

void deleteNode(ListNode* node) {
        ListNode* curr=node;
        ListNode* nxt=curr->next;
        while(nxt->next!=NULL){
            curr->val=nxt->val;
            curr=nxt;
            nxt=nxt->next;
        }
        curr->val=nxt->val;
        curr->next=NULL;

        
    }
