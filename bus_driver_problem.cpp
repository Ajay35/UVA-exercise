/*
11389 - The Bus Driver Problem
 */
#include <bits/stdc++.h>
using namespace std;
int n,d,r;
int main(){
  //ifstream in;
  //ofstream out;
  //in.open("bus");
  //out.open("bus_out");
  while(cin>>n>>d>>r){
    if(n==0 && d==0 && r==0)
      break;

    int m_route[n],e_route[n];
    for(int i=0;i<n;i++){
      cin>>m_route[i];
    }
    for(int i=0;i<n;i++){
      cin>>e_route[i];
    }
    sort(m_route,m_route+n);
    sort(e_route,e_route+n,greater<int>());
    int diff=0;
    for(int i=0;i<n;i++){
      if(m_route[i]+e_route[i]>d){
	diff+=((m_route[i]+e_route[i])-d);
      }
    }
    cout<<r*diff<<endl;
  }
  return 0;
}
