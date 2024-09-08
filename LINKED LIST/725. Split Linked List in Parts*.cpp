
class Solution {
public:
int lengthOfLL(ListNode*head){
    ListNode*temp=head;
    int length=0;
    while(temp){
        temp=temp->next;
        length++;
    }
    return length;
}
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int n=lengthOfLL(head);
        int remainderParts=n%k;
        ListNode*temp=head;
        for(int i=0;i<k;i++){
            //first add n/k nodes in the currPart
            ListNode* currListHead=new ListNode(-1);
            ListNode* currListTail=currListHead;
            for(int j=0;j<n/k;j++){
                currListTail->next=temp;
                currListTail=temp;
                temp=temp->next;

            }
            //and then add one node to number of remiander parts
            if(remainderParts){
               currListTail->next=temp;
                currListTail=temp;
                temp=temp->next;
                remainderParts--;
            }
            currListTail->next=NULL;//don't forget to add NULL that makes the currList complete
            ans[i]=currListHead->next;
        }
        return ans;
    }
};
