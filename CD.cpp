#include <bits/stdc++.h>
using namespace std;
vector<int> sol,best;
int n,m,ans,arr[30];
void find(int i,int cur){
  if(i==m){//base case when all tracks are covered
    if(cur>ans){
      ans=cur;
      best.clear();
      for(auto a: sol){
	best.push_back(a);
      }
    }
    return ;
  }
  find(i+1,cur);//skip ith track without adding
  if(arr[i]+cur<=n){
    sol.push_back(arr[i]);
    find(i+1,cur+arr[i]);//backtrack
    sol.pop_back();
  }
}

int main()
{
  while(cin>>n>>m){

    for(int i=0;i<m;i++)
      cin>>arr[i];
    ans=0;
    find(0,0);
    int sum=0;
    for(auto x:best){
      sum+=x;
      cout<<x<<" ";
    }
    cout<<"sum:"<<sum<<endl;
  }
  return 0;
}
