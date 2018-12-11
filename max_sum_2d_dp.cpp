/* 108 - Maximum Sum  */

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
  ifstream in;
  ofstream out;
  in.open("matrix");
  out.open("matrix_o");
  while(in>>n){
    int arr[n][n];

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	in>>arr[i][j];
	if(i>0) arr[i][j]+=arr[i-1][j];
	if(j>0) arr[i][j]+=arr[i][j-1];
	if(i>0 && j>0) arr[i][j]-=arr[i-1][j-1];
      }
    }
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	for(int k=i;k<n;k++){
	  for(int l=j;l<n;l++){
	    int sum=arr[k][l];
	    if(i>0) sum-=arr[i-1][l];
	    if(j>0) sum-=arr[k][j-1];
	    if(i>0 && j>0) sum+=arr[i-1][j-1];
	    maxx=max(maxx,sum);
	  }
	}	
      }
    }
    out<<maxx<<endl;
  }
  return 0;
}
