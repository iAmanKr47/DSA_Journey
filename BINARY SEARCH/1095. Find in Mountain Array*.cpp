/*
Approach:

STEP 1: FIND PEAK USING BINARY SEARCH
STEP 2: SEARCH FOR TARGET IN LEFT OF THE PEAK [0,PEAKINDEX] USING BINARY SEARCH
STEP 3: IF TARGET NOT FOUND IN LEFT PART THEN SEARCH FOR IT IN RIGHT PART

*/


class Solution {
public:
    int binarySearch(int s,int e,int target, MountainArray &mountainArr){
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            int midVal=mountainArr.get(mid);
            if(midVal==target)return mid;
            else if(midVal>target)e=mid-1;
            else s=mid+1;
           
        }
        return -1;
    }

    int binarySearchDecreasing(int s,int e,int target, MountainArray &mountainArr){
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            int midVal=mountainArr.get(mid);
            if(midVal==target)return mid;
            else if(midVal<target)e=mid-1;
            else s=mid+1;
           
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int s=0;
        int e=n-1;
        //if(target<mountainArr.get(0) || target<mountainArr.get(n-1))return -1;
        int mid;
        //find peak in the mountain array
        while(s<e){
            mid=(s+e)/2;
            int midVal=mountainArr.get(mid);
            int midValNext=mountainArr.get(mid+1);
            if(midVal<midValNext)s=mid+1;
            else e=mid;
        }
        int peakIndex=s;
        int peak=mountainArr.get(peakIndex);
        //now binary search for target in left part of peak
        int left=binarySearch(0,peakIndex,target,mountainArr);
        if(left!=-1)return left;
        //now binary search for target in right of the peak of the mountain if no
        return binarySearchDecreasing(peakIndex+1,n-1,target,mountainArr);
        
    }
};
