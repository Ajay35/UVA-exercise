/* 108 - Maximum Sum  */

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  while(cin>>n){
    int arr[n][n];

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cin>>arr[i][j];
      }
    }
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	for(int k=i;k<n;k++){
	  for(int l=j;l<n;l++){
	    int sum=0;
	    for(int p=i;p<=k;p++){
	      for(int q=j;q<=l;q++){
		sum+=arr[p][q];
	      }
	    }
	    maxx=max(maxx,sum);
	  }
	}	
      }
    }
    cout<<maxx<<endl;
  }
  return 0;
}
