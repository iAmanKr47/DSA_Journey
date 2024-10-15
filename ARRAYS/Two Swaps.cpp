bool checkSorted(vector<int> &arr) {
        // code here.
        int n=arr.size();
        int cnt=0;
        int i=0;
        while(i<n){
            if(arr[i]!=i+1){
                swap(arr[i],arr[arr[i]-1]);
                cnt++;
            }
            else i++;
            if(cnt>2)return false;
        }
        if(cnt>2)return false;
        return true;
    }
