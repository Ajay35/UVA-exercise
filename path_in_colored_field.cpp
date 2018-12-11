/* 10102 - The path in the colored field  */

#include <bits/stdc++.h>
using namespace std;
int m;

int main(){
  while(cin>>m){

    string arr[m];
    string str;
    for(int i=0;i<m;i++){
      cin>>arr[i];
    }

    int ans=0;
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
	if(arr[i][j]=='1'){
	  int min_local=INT_MAX;
	  for(int k=0;k<m;k++){
	    for(int l=0;l<m;l++){
	      if(arr[k][l]=='3'){
		min_local=min(min_local,(abs(i-k)+abs(j-l)));
	      }
	    }
	  }
	  ans=max(ans,min_local);
	}	
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
