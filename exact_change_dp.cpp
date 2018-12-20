#include <bits/stdc++.h>
using namespace std;

int n,t,c,coins[100];
int am,ans_c;
void solve(int i,int s,int ch){
  if(i==c || s>=n){
    if(s>=n && (s<am || ch<ans_c)){
      am=s;
      ans_c=ch;
    }
    return;
  }
  solve(i+1,s,ch);
  solve(i,s+coins[i],ch+1);
  solve(i+1,s+coins[i],ch+1);
}

int main(){
  ifstream in;
  ofstream out;
  in.open("coin.txt");
  out.open("coin_o");
  in>>t;
  int cs=1;
  while(t--){
    cout<<cs++<<endl;
    am=INT_MAX;
    ans_c=INT_MAX;
    in>>n>>c;

    for(int i=0;i<c;i++)
      in>>coins[i];

    solve(0,0,0);
    out<<am<<" "<<ans_c<<endl;
  }
  return 0;
}
