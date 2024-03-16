
int findMaxLength(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        int maxLen=0;
        unordered_map<int,int>mp ;//cnt,index at which cnt occureed first
        mp[0]=-1;//for zero occrence index should be -1 //example test case [0,1]
        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt++;
            else cnt--;

            if(mp.find(cnt)!=mp.end()){
             maxLen=max(maxLen,i-mp[cnt]);
            }
            else mp[cnt]=i;
        }

      return maxLen;
    }


//explainatory code 2
int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> sumMap;
        int maxLength = 0;
        int sum = 0;
        
        sumMap[0] = -1; // Initialize with 0 sum at index -1
        
        for (int i = 0; i < nums.size(); ++i) {
            // Increment sum for 1, decrement for 0
            sum += (nums[i] == 1) ? 1 : -1;
            
            // If the same sum is encountered again, it means that
            // the subarray between the previous occurrence and this
            // one has equal number of 0s and 1s
            if (sumMap.find(sum) != sumMap.end()) {
                maxLength = std::max(maxLength, i - sumMap[sum]);
            } else {
                sumMap[sum] = i; // Store the index of first occurrence of sum
            }
        }
        
        return maxLength;
    }
