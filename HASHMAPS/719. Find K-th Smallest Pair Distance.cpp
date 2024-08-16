//refer MIK

//heap soltuion (TLE solution)(16/19 test cases passed)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int mini=INT_MAX;
        priority_queue <int> pq;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
            {
                pq.push(abs(nums[i]-nums[j]));
                if(pq.size()>k)pq.pop();
            }

        }
        return pq.top();

    }
};


//CODE 2: MAP BASED APPROACH
     //MAX_ELEMENT=M
     // T.C: O(n^2 +M) ~ O(n^2)
     // S.C: O(M)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxEle=*max_element(begin(nums),end(nums));
        int minEle=*min_element(nums.begin(),nums.end());
        int diff=maxEle-minEle;
        vector<int>diffrence(diff+1,0);//create a map storing the count of pairs having a particular diffrernce
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int d=abs(nums[j]-nums[i]);
                diffrence[d]++;
            }
        }
        for(int i=0;i<diffrence.size();i++){
            k-=diffrence[i];
            if(k<=0)return i;
        }
        return -1;
    }
};
