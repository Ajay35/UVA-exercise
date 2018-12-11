#include <bits/stdc++.h>
using namespace std;
int n,ans[100],c=1;
  ifstream in;
  ofstream out;
bool primes[33]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};  
bool visited[17]={0};
void dfs(int no,int val){
  if(val==n){
    if(n==1 || primes[ans[1]+ans[val]]){
      for(int i=1;i<=n;i++){
	if(i!=n)
	  cout<<ans[i]<<" ";
	else
	  cout<<ans[i];
      }
      cout<<"\n";
      return;
    }
  }
  visited[no]=1;
  for(int i=2;i<=n;i++){
    if(!visited[i] && primes[i+no]){
      ans[val+1]=i;
      dfs(i,val+1);
    }
  }
  visited[no]=0;
  return;
}
int main(){
  ios_base::sync_with_stdio(0);
  //cin.tie(NULL);
  //in.open("primering_in.txt");
  //out.open("primering_out.txt");
  while(cin>>n){
    ans[1]=1;
    cout<<"Case "<<c++<<":"<<"\n";
    //dfs(no,index);
    dfs(1,1);
  }
  
  return 0;
}
