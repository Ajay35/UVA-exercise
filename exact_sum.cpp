#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    //cout<<"value of n:"<<n<<endl;
    int m;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    sort(arr,arr+n);
    cin>>m;
    //cout<<"value of m:"<<m<<endl;
    int i=0,j=n-1,minn=INT_MAX,i_v,j_v;
    while(i<j)
    {
      //cout<<"in while"<<endl;
      if((arr[i]+arr[j])==m)
      {
	if(arr[j]-arr[j]<minn){
	  i_v=arr[i];
	  j_v=arr[j];
	}
	i++;
	j--;
      }
      else if(arr[i]+arr[j]>m)
	j--;
      else if(arr[i]+arr[j]<m)
	i++;
    }
    cout<<"Peter should buy books whose prices are "<<i_v<<" and "<<j_v<<"."<<endl;
    cout<<endl;
  }
  return 0;
}
