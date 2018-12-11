#include <bits/stdc++.h>
using namespace std;
int main(){

  int n;
  cin>>n;
  
  int temp=n;
  bool set=false;
  int count=0;
  while(temp>0){
    if(!(temp&1)){
      if(!set){
	set=true;
	count++;
      }
      else{
	break;
      }
    }
    else{
      count++;
    }
    temp>>=1;
  }
  cout<<count<<endl;
  
  return 0;
}
