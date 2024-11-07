

vector<int> findSplit(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=n-1;
        int totalSum=0;
        for(int i=0;i<n;i++) totalSum+=arr[i];
        / if totalSum is not EVENLY divisible by 3
        // then it CANNOT BE split into three equal parts
        if(totalSum % 3 != 0) { 
            return {-1 , -1};
        }
        int firstVal=arr[0];
        int lastVal=arr[n-1];
        int midVal=totalSum-arr[0]-arr[n-1];
        while(midVal>=firstVal || midVal>=lastVal){
            if(midVal==firstVal && midVal==lastVal){
                return {i,j-1};
            }
            else if(firstVal<midVal && firstVal<lastVal){
                i++;
                firstVal+=arr[i];
                midVal-=arr[i];
            }
            else{
                j--;
                lastVal+=arr[j];
                midVal-=arr[j];
            }
        }
        return {-1,-1};
    }
