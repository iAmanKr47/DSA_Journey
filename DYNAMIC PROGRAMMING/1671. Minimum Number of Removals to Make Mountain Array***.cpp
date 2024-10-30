/*
CONCEPT OF LONGEST INC SUBSEQUENCE 

APPROACH:
TRY TO STORE LIS ( from extreme left to that index ) AND LDS ( from that index to extreme right) FOR EACH INDEX 
CONSIDER EACH INDEX AS POTENTIAL PEAK OF THE MOUNTAIN AND FIND OUT THE LONGEST MOUNTAIN ARRAY WHOSE PEAK IS THE CURRENT INDEX WITH HELP OF LIS AND LDS
NOTE: TO REMOVE MIN ELEMENT FROM THE ARRAY TO MAKE ARRAY AS MOUNTAIN WE NEED TO FIND LONGEST MOUNTAIN SEQUENCE IN THE GIVEN ARRAY.
*/


class Solution {
public:
    void longestIncSeq(vector<int>&nums,vector<int>&dpLIS){
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int j=i-1;
            while(j>=0){
                if(nums[j]<curr){
                    dpLIS[i]=max(dpLIS[i],1+dpLIS[j]);
                }
                j--;
            }
        }
    }

    void longestDecSeq(vector<int>&nums,vector<int>&dpLDS){
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            int j=i+1;
            while(j<n){
                if(nums[j]<curr){
                    dpLDS[i]=max(dpLDS[i],1+dpLDS[j]);
                }
                j++;
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dpLIS(n,1);//LONGEST INC SUBSEQUENCE till that index 
        vector<int>dpLDS(n,1);//LONGEST DEC SUBSEQUENCE till the index to last
        longestIncSeq(nums,dpLIS);
        longestDecSeq(nums,dpLDS);
        int maxLen=0;
        //check for each index as a potential candidate for the peak of the mountain 
        for(int i=0;i<n;i++){
            //this extra check of IF statement is for condition I
            if(dpLIS[i]>1&& dpLDS[i]>1) maxLen=max(maxLen,dpLIS[i]+dpLDS[i]-1);
        }
        return n-maxLen;
    }
};
