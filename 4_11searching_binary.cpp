#include<bits/stdc++.h>
using namespace std; 
int binary_ser(int arr[],int low,int high,int key)
{
  while(low<high)
  {
    int mid=(low+high)/2;
    if(arr[mid]==key)
    {
      return mid;
    }
    else{
      if(key>mid)
      {
        low=mid+1;
      }
      else{
        high=mid-1;
      }
    }
  }
  return -1;
}
int main ()
{
  int arr[30];
  int n;
  cout <<"enter the size of array" <<"\n";
  cin >>n;
  int key;
  cout <<"enter the element to be found " <<"\n";
  cin >>key;
  cout <<"enter the array elemts " <<"\n";
  for(int i=0;i<n;i++)
  {
    cin >>arr[i];
  }
  int loc=binary_ser(arr,arr[0],arr[n-1],key);
  if(loc!=-1)
  {
  cout <<"locatiion of elemnt " <<key <<" " <<"  is " <<" " <<loc <<"\n";
  }
  else
  {
    cout <<"element not found " <<loc <<"\n";
  }
}
