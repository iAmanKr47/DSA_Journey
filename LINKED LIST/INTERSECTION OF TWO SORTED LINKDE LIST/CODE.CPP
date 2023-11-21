Node* findIntersection(Node* head1, Node* head2)
    {
         
        Node *temp1=head1;
        Node *temp2=head2;
        Node *head3=new Node(-1);
        Node *temp3=head3;
       if(head1==NULL||head2==NULL) return head3;
       
        while(temp1&&temp2){
            
            if(temp1->data==temp2->data){
                Node *newNode=new Node(temp1->data);
                temp3->next=newNode;
                temp3=newNode;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->data<temp2->data){
                 temp1=temp1->next;
            }
            else 
                temp2=temp2->next;
        }
        
        return head3->next;
    }
