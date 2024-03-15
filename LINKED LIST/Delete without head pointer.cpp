//APPROACH 1: TRAVERSE THE LINKED LIST NEXT TO THE DEL_NODE AND COPY THE NEXT NODE DATA IN PREVIOUS NODE.  TC- O(N)

void deleteNode(Node *del_node)
    {
      if(del_node->next==NULL) free(del_node);
      Node *prev=del_node;
      Node* temp=del_node->next;
      while(temp){
          prev->data=temp->data;
          
          temp=temp->next;
          if(temp==NULL) break;
          prev=prev->next;
      }
     prev->next=NULL;
    }

//APPROACH 2: TC-O(1) OPTIMISED APPROACH

void deleteNode(Node *del_node)
    {
        //storing the node next to given node in a pointer.	
    	Node* temp = del_node->next;
    	
    	//copying the data of pointer in the given current node.
    	del_node->data = temp->data;
    	
    	//storing the next node to pointer in link part of current node.
    	del_node->next = temp->next;

    	// freeing memory.
    	free(temp);
    }
