
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node*prev=head;
        Node*curr=head->next;
        Node*front=head->next->next;
        
        while(true){
            curr->next=prev;
            if(front==head){
                front->next=curr;
                return curr;
            }
            
            prev=curr;
            curr=front;
            front=front->next;
            
        }
        
        return curr;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        //when head node is to be deleted
        if(head->data==key){a
        
        Node*curr=head;
        while(curr->next!=head)curr=curr->next;
        curr->next=head->next;
        return head->next;
        }
        
        //when any other node
        Node*prev=head;
        Node*curr=head->next;
        while(curr!=head && curr->data!=key){
            prev=curr;
            curr=curr->next;
        }
        
        if(curr!=head){
            prev->next=curr->next;
        }
        return head;
    }
};
