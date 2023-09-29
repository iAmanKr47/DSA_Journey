vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
         vector<int>ans;
        int s1=0;//s1 is at sarting index of arr
        int e2=m-1;//e2  is at last index of brr
        int firstNumIndex;
        int secondNumIndex;
        int minSumDiff=INT_MAX;
        while(s1<n&&e2>=0){
            int currSum=arr[s1]+brr[e2];
            if(abs(currSum-x)<minSumDiff){
                minSumDiff=abs(currSum-x);
                firstNumIndex=s1;
                secondNumIndex=e2;
                
            }
             if(currSum>x) {
                e2--;
            }
            else        //(currSum<x) 
              s1++;
            
         
            
        }
        ans.push_back(arr[firstNumIndex]);
        ans.push_back(brr[secondNumIndex]);
        return ans;
    }
