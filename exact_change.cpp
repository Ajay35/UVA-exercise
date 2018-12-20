#include <bits/stdc++.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;
 
int main ()
{

  ifstream in;
  ofstream out;
  in.open("coin.txt");
  out.open("coin_o");
  int testCase;
  cin>>testCase;
  
  while (testCase--) {
    int bill;
    cin>>bill;
    
    int coinNumber;
    cin>>coinNumber;
  
  int coins [100 + 5];
  for ( int i = 0; i < coinNumber; i++ )
    cin>>coins[i];
  
  int dp [10000 + 10];
  for ( int i = 0; i < 10010; i++ )
    dp [i] = INT_MAX;
  
  dp [0] = 0;
  
  for ( int i = 0; i < coinNumber; i++ ) {
    for ( int j = 10000; j >= 0; j-- ) {
      if ( dp [j] != INT_MAX && j + coins [i] <= 10000 && dp [j + coins [i]] > dp [j] + 1 ) dp [j + coins [i]] = dp [j] + 1;
    }
  }
  
  for ( int i = bill; i <= 10000; i++ ) {
    if ( dp [i] != INT_MAX ) {
      cout<<i<<" "<<dp[i]<<endl;
      break;
    }
  }
}

return 0;
}
 
