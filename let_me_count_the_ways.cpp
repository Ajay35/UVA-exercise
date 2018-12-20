/*357 - Let Me Count The Ways  */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int coins[5]={1,5,10,25,50};
ll dp[100][30000];

ll solve(int i,int rem){
  // positive case
  if(rem==0){
    return 1;
  }
  // rem amount goes negative,pruning the step
  if(rem<0)
    return 0;
  // coins finished still amount is above zero
  if(i<=0 && rem>=1)
    return 0;
  if(dp[i][rem]!=-1)
    return dp[i][rem];
  return
    dp[i][rem]=solve(i-1,rem)+solve(i,rem-coins[i-1]);

}
int main(){
  ll n,res;
  ifstream in;
  ofstream out;
  in.open("coin.txt");
  out.open("coin_o");
  memset(dp,-1,sizeof(dp));
  for(int i=30000;i>=0;i--){
    solve(5,i);
  }
  while(in>>n){
    if(dp[5][n]==1 || n==0)
      out<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
    else 
      out<<"There are "<<dp[5][n]<<" ways to produce "<<n<<" cents change."<<endl;
  }
  return 0;
}
