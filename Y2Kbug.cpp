#include <bits/stdc++.h>
using namespace std;
vector<long long > sol;
long long  ans=0,s,d;
bool f=false;
bool check(vector<long long> sol){
  for(int i=0;i<=7;i++){
    long long sum=0;
    for(int j=i;j<i+5;j++){
      sum+=sol[j];
    }
    if(sum>0)
      return false;
  }
  return true;
}
void solve(int i,long long cur,vector<long long> sol){
  if(i==12){
    if(cur>ans){
      if(check(sol)){
	ans=cur;
	f=true;
      }
    }
    return;
  }
  sol.push_back(s);
  solve(i+1,cur+s,sol);
  sol.pop_back();
  sol.push_back(d);
  solve(i+1,cur+d,sol);
  sol.pop_back();
}

int main(){
  long long cur;
  ifstream in;
  ofstream out;
  in.open("y2k.txt");
  out.open("y2kout.txt");
  while(cin>>s>>d){
    cur=0;
    d=d*(-1);
    solve(0,cur,sol);
    if(!f){
      cout<<"Deficit"<<endl;
      cur=0;
      ans=0;
    }
    else{
      cout<<ans<<endl;
      f=false;
      cur=0;
      ans=0;
    }
  }
  return 0;
}
