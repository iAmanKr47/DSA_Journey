//LAZY SORTING TECHNIQUE
int lengthOfLIS(vector<int>& nums) {
        //patience sorting 
        int n=nums.size();
        vector<int>sorted; //sorted array intially empty
        //STEPS INVOLVED
        //just greater than the nums[i]
        //-> if found than replace it with nums[i]
        //->else append it in the the sorted list

        for(int i=0;i<n;i++){
                auto it =lower_bound(sorted.begin(),sorted.end(),nums[i]);
                if(it==end(sorted))sorted.push_back(nums[i]);
                else *it=nums[i];
        }
        return sorted.size();

    }
