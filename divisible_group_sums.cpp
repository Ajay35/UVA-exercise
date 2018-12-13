/* 10616 - Divisible Group Sums  */

#include <bits/stdc++.h>
using namespace std;


#define MAX 205

int N, M, D, Q;
int arr[MAX], memo[MAX][MAX][15];

int dp(int i, int sum, int c){
  if(c == M && sum == 0)
    return 1;
  if(c == M && sum != 0)
    return 0;
  if(i == N)
    return 0;
  if(memo[i][sum][c] != -1)
    return memo[i][sum][c];
  
  memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+arr[i])%D, c+1);

  return memo[i][sum][c];
}

int main(){
  int i, j, res;
  ifstream in;
  ofstream out;
  in.open("knap");
  out.open("knap_o");
  j = 1;
  while(1)
    {
      in>>N>>Q;
      
      if(N == 0 && Q == 0)
	break;
      
      for(i = 0; i < N; i++){
	in>>arr[i];
      }
      out<<"SET "<<j<<":"<<endl;
      for(i = 0; i < Q; i++){
	in>>D>>M;
	memset(memo, -1, sizeof(memo));
	res = dp(0, 0, 0);
	out<<"QUERY "<<i+1<<": "<< res<<endl;
      }
      j++;
    }	
  return 0;
}
