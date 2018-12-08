#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t,n;
  cin>>t;
  while(t--)
  {
    int q,q_x;
    cin>>n;
    string comp[n];
    int price[n][2];
    
    for(int i=0;i<n;i++){
      cin>>comp[i];
      cin>>price[i][0]>>price[i][1];	
    }
    cin>>q;
    while(q--){
      cin>>q_x;
      int count=0;
      string str="";
      for(int i=0;i<n;i++){
       
	if(q_x >= price[i][0] && q_x<=price[i][1]){
	  if(count==0)
	    str=comp[i];
	  count++;
	}
      }
      if(count==1)
	  cout<<str<<endl;
      else
	cout<<"UNDETERMINED"<<endl;
    }
    if(t)
      cout<<endl;      
  }
  return 0;
}
