/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

void sort(Node **head)
    {
        if(*head==NULL||(*head)->next==NULL||(*head)->next->next==NULL)return ;
         Node *asc=*head;
         Node *desc=(*head)->next;
         Node *tempHead=desc;
         while(desc && desc->next ){
             asc->next=asc->next->next;
             desc->next=desc->next->next;
             
             asc=asc->next;
             desc=desc->next;
             
         }
         //reversing decreasing linked list
         Node *curr=tempHead;
         Node* prev=NULL;
         
         while(curr){
             Node * nextNode=(curr)->next;
             curr->next=prev;
             prev=curr;
             curr=nextNode;
         }
        asc->next=prev;    
    }
