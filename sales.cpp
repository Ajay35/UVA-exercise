#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    for(int i=1;i<n;i++){
      int count=0;
      for(int j=0;j<i;j++){
	if(arr[i]>=arr[j])
	{
	  //cout<<arr[j]<<endl;
	  count++;
	}
      }
      sum+=count;
    }
    cout<<sum<<endl;
  }
  return 0;
}
