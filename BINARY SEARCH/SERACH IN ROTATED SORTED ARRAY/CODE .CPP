// 33.SERACH IN ROTATED SORTED ARRAY I

int search(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target) return mid;
            //left part is sorted
            if(arr[s]<=arr[mid]){
                // target present at left part
                if(arr[s]<=target && arr[mid]>=target) e=mid-1;
                //target present at right part
                else s=mid+1;
            }
            //right is sorted
            else{
                //target exist in right part
                if(arr[mid]<=target && arr[e]>=target) s=mid+1;
                //exist in left part
                else e=mid-1;
            }
        }
        return -1;
    }



// 81.SEARCH IN ROTATED SORTED ARRAY II

bool search(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target) return true;
            if(arr[s]==arr[mid] && arr[e]==arr[mid]){
                s++;
                e--;
                continue;
            }
            //left part is sorted
            if(arr[s]<=arr[mid]){
                // target present at left part
                if(arr[s]<=target && arr[mid]>=target) e=mid-1;
                //target present at right part
                else s=mid+1;
            }
            //right is sorted
            else{
                //target exist in right part
                if(arr[mid]<=target && arr[e]>=target) s=mid+1;
                //exist in left part
                else e=mid-1;
            }
        }
        return false;
    }
