struct Node* arrangeCV(Node *head)
    {
      unordered_set<char>st;
      st.insert({'a','e','i','o','u'});
      Node*vowelHead=new Node(49);
      Node*vowelNode=vowelHead;
      Node*consonantHead=new Node(49);
      Node*consonantNode= consonantHead;
      Node*temp=head;
      while(temp){
          if(st.find(temp->data)!=st.end()){
            vowelNode->next=temp;
            temp=temp->next;
            vowelNode=vowelNode->next;
            vowelNode->next=NULL;
            
          }
          else{
              consonantNode->next=temp;
              temp=temp->next;
              consonantNode=consonantNode->next;
              consonantNode->next=NULL;
              
          }
          
        }
      if(consonantNode==consonantHead || vowelNode==vowelHead)return head; //if all elemnts are either vowels or all are consonants
      
      vowelNode->next=consonantHead->next;
      return vowelHead->next;
      
    }
