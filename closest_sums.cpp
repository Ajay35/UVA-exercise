#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,c=1;
  while(cin>>n){
    if(n==0)
      break;

    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    cin>>m;
    int q[m];
    for(int i=0;i<m;i++)
      cin>>q[i];

    cout<<"Case "<<c++<<":"<<endl;
    for(int k=0;k<m;k++){
      int sum=INT_MAX,ans;
      
      for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  if(i!=j &&  sum>abs(q[k]-(arr[i]+arr[j]))){
	    sum=abs(q[k]-(arr[i]+arr[j]));
	    ans=arr[i]+arr[j];
	  }
	}
      }
      cout<<"Closest sum to "<<q[k]<<" is "<<ans<<"."<<endl;
    }
  }
  return 0;
}
