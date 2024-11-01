
/*
  MONOTONIC STACK BASED PROBLEM
  T.C:O(N)
  S.C:O(N)
*/
int maxWidthRamp(vector<int>& nums) {
        stack<int>st;//monotanic decresing stack //stores index of the element
        int maxWid=0;
        for(int i=0;i<nums.size();i++){//O(N)
            if(st.size()==0)st.push(i);
            else if(nums[st.top()]>nums[i])st.push(i);
        }
  
        //O(N)
        for(int j=nums.size()-1;j>=0;j--){
            if(st.size()==0)break;
            while(st.size()>0  && nums[st.top()]<=nums[j]){
                int i=st.top();
                maxWid=max(maxWid,j-i);
                st.pop();
            }
        }
        return maxWid;
    }
