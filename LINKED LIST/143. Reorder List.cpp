// find middle node of LL
// reverse second half of the LL
// Merge two LL using two pointer

void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
       //go to middle node 
       ListNode *slow=head;
       ListNode *fast=head; 
       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       //reverse second half
       ListNode *prev =NULL, *cur=slow->next, *Next;
        while (cur) {
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }

        slow->next=NULL;
        //two new linked list created merge two linked list
        ListNode *head1=head;
        ListNode *head2=prev;
        while(head1 && head2){
         auto next1=head1->next;
         auto next2=head2->next;
         head1->next=head2;
         head1=next1;
         head2->next=head1;
         head2=next2;

        }
    }
