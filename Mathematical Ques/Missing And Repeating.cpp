/*
In-Place and Sum Formula
Calculate the sum of the first size natural numbers. Traverse the array. While traversing, use the absolute value of every element as an index 
and make the value at this index negative to mark it visited and subtract this value from the missing variable. 
If something is already marked negative, then this is the repeating element. After traversing, the ‘missing’ variable holds the value of the missing element.
  */


vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long  currSum=0;
        int repeat;
        long long totalSum=(1ll*n*(n+1))/2;
        for(auto i:arr)currSum+=i;
        
        for(int i=0;i<arr.size();i++){
            if(arr[abs(arr[i])-1]<0){
                repeat=abs(arr[i]);
                break;
            }
            arr[(abs)(arr[i])-1]=(-1)*arr[abs(arr[i])-1];
        }
        return {repeat,abs((int)(totalSum-(currSum-repeat) ))};
        
    }
