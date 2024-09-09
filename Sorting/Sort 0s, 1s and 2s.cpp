
/*      DUTCH NATIONAL FLAG ALGORITHM

        0 to low-1: contains 0 only
        low to mid-1: contains 1 only
        mid to high : contains unsorted 0,1,2
        high+1 to n-1: contains 2 only
        
*/
void sort012(vector<int>& arr) {
        
        int n=arr.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[high],arr[mid]);
                high--;
            }
        }
    }
