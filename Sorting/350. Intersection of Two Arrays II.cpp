//try question 349.Intersection of Two Arrays also

//code 1: optimised approach of two pointers

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
         vector<int>ans;
        int n1=nums1.size();
        int n2=nums2.size();
        int p1=0;
        int p2=0;
        while(p1<n1&&p2<n2){
            if(nums1[p1]<nums2[p2])p1++;
            else if(nums1[p1]==nums2[p2]){
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else p2++;
        }
        return ans;
    }

//code 2 : use of map

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            um[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (um.find(nums2[i]) != um.end()) {
                res.push_back(nums2[i]);
                um[nums2[i]]--;
                if(um[nums2[i]]==0)um.erase(nums2[i]);
            }
        }
        return res;
    }
