/* 11292 - Dragon of Loowater  */

#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
  ifstream in;
  ofstream out;
  //in.open("dragon.txt");
  //out.open("dragon_o.txt");
  while(cin>>n>>m){
    if(n==0 && m==0)
      break;
    int d[n],k[m];

    for(int i=0;i<n;i++)
      cin>>d[i];
    for(int i=0;i<m;i++)
      cin>>k[i];
    sort(d,d+n);
    sort(k,k+m);
    int g=0,c=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	if(d[i]<=k[j]){
	  g+=(k[j]);
	  k[j]=-1;
	  c++;
	  break;
	}
      }
    }
    if(c==n)
      cout<<g<<endl;
    else
      cout<<"Loowater is doomed!"<<endl;
  }
  return 0;
}
