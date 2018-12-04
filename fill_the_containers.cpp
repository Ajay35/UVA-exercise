#include<bits/stdc++.h>
using namespace std;
int check(int arr[],int mid,int m,int n)
{
 
  int c=0,cont=1;
  for(int i=0;i<n;i++)
  {
    if(c+arr[i]<=mid)
    {
      c+=arr[i];
    }
    else
    {
      c=arr[i];
      cont++;
      if(arr[i]>mid or cont>m)
      {
	return 0;
      }
    }
  }
  return 1;
}
int main()
{
  int n,m,c;
  while(cin>>n)
  {
    int sum=0;
    cin>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
  int l=0,r=sum,minn=INT_MAX;
    while(l<r)
    {
      int mid=l+(r-l)/2;
      if(check(arr,mid,m,n))
      {
	r=mid;
      }
      else
      {
	l=mid+1;
      }
    }
    cout<<l<<endl;
  }
  return 0;
}
