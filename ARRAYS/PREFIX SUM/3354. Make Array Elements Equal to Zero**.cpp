/*For i, we track the sum of elements on the left and right of i.

If nums[i] == 0:

if sums are equal, we can go in either direction (+2 to the result).
If the difference between sums is 1, we can go in the direction with the larger sum (+1 to the result).
We use the prefix sum array ps to get the sums.
*/

int countValidSelections(vector<int>& nums) {
        int totalSum=0;
        for(auto i:nums)totalSum+=i;
        int currSum=0;
        int cnt=0;
        for(auto i:nums){
             if(i==0){
                if(currSum==totalSum-currSum)cnt+=2;
                else if(abs(currSum-(totalSum-currSum))==1)cnt+=1;
             }
             currSum+=i;
        }
        return cnt;
    }
