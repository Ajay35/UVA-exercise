/*11264 - Coin Collector  */

#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ifstream in;
  ofstream out;
  //in.open("coin.txt");
  //out.open("coin_o.txt");
  int i,j,n,sum,ans,t;
  cin>>t;
  while(t--){
    cin>>n;
    int coins[n];
    for(i=0;i<n;i++){
      cin>>coins[i];
    }
    
    sum=coins[0];ans=1;		//first coin
    
    for(i=1;i<n-1;i++){
      if(coins[i]+sum<coins[i+1]){
	sum+=coins[i];
	ans++;
      }
    }
    
    cout<<ans+1<<"\n";	//last coin
    
  }
  return 0;
}
