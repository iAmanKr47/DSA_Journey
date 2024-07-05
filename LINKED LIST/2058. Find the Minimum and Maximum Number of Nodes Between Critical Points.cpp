//HINT 1: maxDis is always diffrence b/w first critical node and last critical node.
//HINT 2: minDis can be b/w any two adjacent critical nodes.
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        int minDis=INT_MAX;
        int maxDis;
        int firstCriticalPoint=-1;
        int lastCriticalPoint=-1;
        int prevCriticalPoint;
        int index=2;//curr will start from 2nd node //1 based indexing is used
        while(curr->next){
            if( (curr->val>prev->val && curr->val>curr->next->val)||(curr->val<prev->val && curr->val<curr->next->val) )
            {
                if(firstCriticalPoint==-1){//this if statement will excute atmost 1 time
                    firstCriticalPoint=index;
                    prevCriticalPoint=index;

                    index++;
                   prev=curr;
                   curr=curr->next;
                    continue;
                }
                else {
                    lastCriticalPoint=index;
                    minDis=min(minDis,index-prevCriticalPoint);
                    prevCriticalPoint=index;
                }
            }
            index++;
            prev=curr;
            curr=curr->next;
        }
        if(lastCriticalPoint==-1)return {-1,-1};//there is less than 2 nodes
        maxDis=lastCriticalPoint-firstCriticalPoint;

        return {minDis,maxDis};
    }
