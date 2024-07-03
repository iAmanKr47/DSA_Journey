//Optimised approach
Node* removeAllDuplicates(struct Node* head) {
        if(head->next==NULL)return head;
        Node* newHead=new Node(-1);
        Node* currNode=newHead;
        Node* refrenceNode=head;
        
        while(refrenceNode){
            if(refrenceNode->next==NULL || refrenceNode->next->data!=refrenceNode->data)
            {
                currNode->next=refrenceNode;
                currNode=refrenceNode;
                refrenceNode=refrenceNode->next;
                
            }
            else{
                Node *temp=refrenceNode->next;
                while(temp && temp->data==refrenceNode->data)temp=temp->next;
                refrenceNode=temp;
            }
        }
        currNode->next=NULL;
        return newHead->next;
    }

//alternate approach using MAP
Node* removeAllDuplicates(struct Node* head) {
        // code here
        if(head->next==NULL)return head;
        
        Node* newNode=new Node(-1);
        newNode->next=head;
        Node* newHead=newNode;
        map<int,int>mp;
        Node*temp=head;
        while(temp){
            mp[temp->data]++;
            temp=temp->next;
        }
        for(auto i:mp){
            if(i.second==1){
                newHead=newHead->next;
                newHead->data=i.first;
            }
            
        }
        if(newHead->data==-1)return NULL;
        newHead->next=NULL;
        return newNode->next;
    }

//can use unordered_map : for that see editorial of this ques on GFG 
