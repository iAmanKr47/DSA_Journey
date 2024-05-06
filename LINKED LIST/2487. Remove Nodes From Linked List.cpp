

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode* nextNode;
        while(curr){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head ||!head->next)return head;
        ListNode* newHead=reverseList(head);//REVERSE LIST
        ListNode* temp=newHead;
        int maxi=newHead->val;//KEEP TARCK OF MAXIMUM FROM LEFT-RIGHT
        while(temp->next){
            if(temp->next->val>=maxi){
                maxi=temp->next->val;
                temp=temp->next;
            }
            else{
                temp->next=temp->next->next;
            }
        }

        return reverseList(newHead);//REVERSE AGAIN FOR ORGINAL ORDER
    }
};
