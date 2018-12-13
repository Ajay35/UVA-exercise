#include <bits/stdc++.h>
using namespace std;
int main(){

  int n;
  while(cin>>n){
    if(n==0)
      break;
    int arr[n],arr1[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
      arr1[arr[i]-1]=i+1;
    }
    bool amb=true;

    
    
    for(int i=0;i<n;i++){
      if(arr[i]!=arr1[i]){
	//cout<<"break"<<endl;
	amb=false;
	break;
      }
    }
    if(amb)
      cout<<"ambiguous"<<endl;
    else
      cout<<"not ambiguous"<<endl;
  }
  return 0;
}
