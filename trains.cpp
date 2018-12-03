#include <bits/stdc++.h>
using namespace std;

bool check(int arr1[],int n)
{
  stack<int> st1;
  vector<int> res;
  int ind=0;
  for(int i=0;i<n;)
  {
    if(i+1!=arr1[ind])
    {
      if(i+1<arr1[ind])
      {
	st1.push(i+1);
	i++;
      }
      else
      {
	if(!st1.empty())
	{
	  res.push_back(st1.top());
	  st1.pop();
	  ind++;
	}
      }
    }
    else
    {
      //cout<<"pushedback:"<<i+1<<endl;
      res.push_back(i+1);
      ind++;
      i++;
    }
  }
  while(!st1.empty())
  {
    res.push_back(st1.top());
    st1.pop();
  }

  for(int i=0;i<n;i++)
  {
    if(arr1[i]!=res[i])
      return false;
    // cout<<res[i]<<" ";
  }
  //cout<<endl;
  return true;
}

int main()
{
  int n;
  while(cin>>n)
  {
    int arr1[n];
    for(int i=0;i<n;i++)
      arr1[i]=i+1;
    if(n==0)
      break;
    int t=n;
    int arr2[n];
    while(true)
    {
      //cout<<"entering input"<<endl;
      cin>>arr1[0];
      if(arr1[0]==0)
	break;
      for(int i=1;i<n;i++)
      {
	cin>>arr1[i];
      }
      
      if(check(arr1,n))
	cout<<"Yes"<<endl;
      else
	cout<<"No"<<endl;
    }
    cout<<endl;
  }
  return 0;
}
