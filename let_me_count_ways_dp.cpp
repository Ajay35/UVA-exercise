/*357 - Let Me Count The Ways */
#include<bits/stdc++.h>
using namespace std;

int m, coins[5]={1,5,10,25,50};
long ways[30010]={0};
 
int main(){
  ifstream in;
  ofstream out;
  //in.open("coin.txt");
  //out.open("coin_o");
  ways[0]=1;
  for(int i=0;i<5;i++){
    for(int j=coins[i];j<=30000;j++){
      ways[j] += ways[j - coins[i]];
    }
  }
  while(cin>>m){
    if(ways[m] == 1)
      cout<<"There is only 1 way to produce "<<m<<" cents change."<<endl;
    else
      cout<<"There are "<<ways[m]<<" ways to produce "<<m<<" cents change."<<endl;
  }
  return 0;
}
