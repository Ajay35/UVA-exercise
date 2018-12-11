/* 481 - What Goes Up  */
#include <bits/stdc++.h>
using namespace std;

set<int> d;
set<int>::iterator it;
int ans, n;
 
int main(){
  int x;
  ifstream in;
  ofstream out;
  //in.open("lis");
  //out.open("lis_o");
  while (cin>>x){    
    d.insert(x);
    it=d.find(x);
    it++;
    if(it!=d.end())
      d.erase(it);
  }
  cout<<d.size()<<endl;
  return 0;
}
