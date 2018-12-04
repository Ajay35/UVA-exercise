#include <bits/stdc++.h>
using namespace std;
int check(vector<int> arr,int n,int mid)
{
  
  for(int i=1;i<=n;i++)
  {
    if(arr[i]-arr[i-1]==mid)
      mid--;
    else if(arr[i]-arr[i-1]>mid)
      return 0;
  }
  return 1;
}
int main()
{
  int t,n,c=1;
  cin>>t;
  while(t--)
  {
    cin>>n;
    vector<int> arr;
    int x;
    arr.push_back(0);
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      arr.push_back(x);
    }
    int l=0,h=10000000;
    while(l<h)
    {
      int mid=(l+h)>>1;
      if(check(arr,n,mid))
	h=mid;
      else
	l=mid+1;
    }
    cout<<"Case "<<c++<<": "<<l<<endl;
  }
  return 0;
}
