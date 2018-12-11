#include <bits/stdc++.h>
using namespace std;
int t,n,arr[12],cur;
set<vector<int>> ans;
vector<int> sol;
void solve(int i,int cur){
  if(i==n){
    if(cur==t){
      ans.insert(sol);
    }
    return;
  }
  solve(i+1,cur);

  if(arr[i]+cur<=t){
    sol.push_back(arr[i]);
    solve(i+1,arr[i]+cur);
    sol.pop_back();
  }
  
}

int main(){
  //ifstream in;
  //ofstream out;
  //in.open("sum");
  //out.open("sumout");
  
  while(cin>>t>>n){
    if(t==0 && n==0)
      break;
    cur=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    solve(0,cur);
    cout<<"Sums of "<<t<<":"<<endl;
    std::set<vector<int>>::reverse_iterator rit;
			     if(ans.size()==0){
			       cout<<"NONE"<<"\n";
			       continue;
			     }
    for (rit=ans.rbegin(); rit != ans.rend(); ++rit){
      const vector<int>& i = (*rit); // HERE we get the vector
      int s=i.size();
      for(int j=0;j<s;j++){
	if(j!=s-1)
	  cout<<i[j]<<"+";
	else
	  cout<<i[j];
      }
      cout<<"\n";
    }
	   ans.clear();
  }
    cout<<"\n";
  return 0;
}
