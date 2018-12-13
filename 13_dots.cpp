/* 10819 - Trouble of 13-Dots  */


#include <bits/stdc++.h>
using namespace std;

int m,n,p,f,arr[100][2],dp[110][15000];

int solve(int i,int w){

  /* pruning the search tree for unnnecessary branches  */
  if(w>m && m<1800)
    return -1000;

  if(w>m+200)
    return -1000;
  
  if(i==n){
    if(w>m && w<=2000)
      return -1000;
    return 0;
  }
  if(dp[i][w]!=-1)
    return dp[i][w];
  
  return dp[i][w]=max(solve(i+1,w),arr[i][1]+solve(i+1,arr[i][0]+w));
}


int main(){

  cin>>m>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i][0]>>arr[i][1];
  }
  memset(dp,-1,sizeof(dp));
  solve(0,0);
  cout<<dp[0][0]<<endl;
  return 0;
}
