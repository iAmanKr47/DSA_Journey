//Hashing Aprroach
int longestConsecutive(vector<int> &arr) {
    unordered_set<int> st;
    int res = 0;

    // Hash all the array elements
    for (int val: arr)
        st.insert(val);

    // check each possible sequence from the start then update optimal length
    for (int val: arr) {
      
        // if current element is the starting element of a sequence
        if (st.find(val) != st.end() && st.find(val-1) == st.end()) {
          
            // Then check for next elements in the sequence
            int cur = val, cnt = 0;
            while (st.find(cur) != st.end()) {
                
                // Remove this number to avoid recomputation
                st.erase(cur);
                cur++;
              	cnt++;
            }

            // update  optimal length
            res = max(res, cnt);
        }
    }
    return res;
}

//sorting 

int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        sort(begin(arr),end(arr));
        int cnt=1;
        int maxLength=0;
        for(int r=1;r<n;r++){
            if(arr[r]==arr[r-1]){
                continue;
            }
            if(arr[r]-1 != arr[r-1]){
                maxLength=max(cnt,maxLength);
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        
        maxLength=max(maxLength,cnt);
        return maxLength;
    }
