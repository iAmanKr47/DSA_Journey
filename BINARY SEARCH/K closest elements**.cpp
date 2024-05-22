//topics: binary search , two pointers

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int>ans;
        int e=upper_bound(arr.begin(), arr.end(), x)-arr.begin();
        int s=e-1;
        if(s>=0 && arr[s]==x)s--;
        while(ans.size()<k && s>=0 && e<n){
            if(abs(x-arr[s])<abs(x-arr[e])){
                ans.push_back(arr[s--]);
            }
            else {
              ans.push_back(arr[e++]);
            }
        }
        while(s>=0 &&ans.size()<k){
         ans.push_back(arr[s--]);
         
        }
        while(e<n&&ans.size()<k){
            ans.push_back(arr[e]);
            e++;
           
        }
        return ans;
    }
};
