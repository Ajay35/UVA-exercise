#include <bits/stdc++.h>
using namespace std;
int main()
{
  int kik;
  while(cin>>kik){
    if(kik==0)
      break;
    int arr[kik];
    for(int i=0;i<kik;i++)
      cin>>arr[i];
    sort(arr,arr+kik);
    for(int i=0;i<kik-6+1;i++){
      for(int j=i+1;j<kik-6+2;j++){
	for(int k=j+1;k<kik-6+3;k++){
	  for(int l=k+1;l<kik-6+4;l++){
	    for(int m=l+1;m<kik-6+5;m++){
	      for(int n=m+1;n<kik-6+6;n++){
		printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k],arr[l], arr[m], arr[n]);
	      }
	    }
	  }
	}
      }
    }
  }
  return 0;
}
