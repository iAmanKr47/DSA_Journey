#include <iostream>
using namespace std;

void merge(int *arr,int s,int e)
{
 int mid=(s+e)/2;
  //CREATE TWO NEW ARRAY OF SIZE START TO MID AND  MID+1 TO END 
  int len1=mid-s+1;
  int len2=e-mid;
  int *left=new int[len1];
  int *right=new int[len2];
                            //copy elemnt in array
  int mainArrayIndex=s;
  for(int i=0;i<len1;i++)
    left[i]=arr[mainArrayIndex++];

  mainArrayIndex=mid+1;
  for(int i=0;i<len2;i++)
    right[i]=arr[mainArrayIndex++];


                        //merge 2 sort logic 
  int index1=0;
  int index2=0;
   mainArrayIndex=s;
  while(index1<len1&&index2<len2)
    {
      if(left[index1]<right[index2])
        arr[mainArrayIndex++]=left[index1++];
      else //if(right[index2]<left[index1])
        arr[mainArrayIndex++]=right[index2++];
    }
  if(index1<len1)
     arr[mainArrayIndex++]=left[index1++];
  if(index2<len2)
     arr[mainArrayIndex++]=right[index2++];
}


void  mergeToSort(int *arr,int s,int e)
{
 int mid=(s+e)/2;

  if(s>=e)
  {
    return ;
    }
  //sort left part 
  mergeToSort(arr, s,mid);
  //sort right part
  mergeToSort(arr,mid+1,e);

merge(arr,s,e);  
//return 0;
}


int main()
{
  int arr[]={10,2,29,25,50,2,13,101,40,100};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<"size of array "<<n<<"\n\n";
  int s=0;
  int e=n-1;
  mergeToSort(arr,s,e);
  for(int i=0;i<n;i++)
    cout<<"\t"<<arr[i];
  return 0;
}