/* 11456 - Trainsorting  */
#include <bits/stdc++.h>
using namespace std;

int lds(int arr[], int n) 
{
  int lds[n],lis[n]; 
    int i, j,max=0; 
 
    for(int i = n - 1; i >= 0; i--) {
      lis[i] = 1;
      for(int j = i + 1; j < n; j++) {
	if(arr[i] < arr[j]) {
	  lis[i] = std::max(lis[j] + 1, lis[i]);
	}
      }
    }
    for(int i = n - 1; i >= 0; i--) {
      lds[i] = 1;
      for(int j = i + 1; j < n; j++) {
	if(arr[i] > arr[j]) {
	  lds[i] = std::max(lds[j] + 1, lds[i]);
	}
      }
    }
  
      int ans = 0;
      for(int i = 0;i<n; i++) {
	ans = std::max(ans,lis[i] + lds[i] - 1);
      }
      for(i = 0; i < n; i++){ 
	if(max < lds[i]){ 
	  max = lds[i];
	}
      }
    return ans; 
} 
int main() 
{
  ifstream in;
  ofstream out;
  //in.open("lis");
  //out.open("lis_o");
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    cout<<lds(arr, n)<<endl; 
  } 
  return 0; 
} 
