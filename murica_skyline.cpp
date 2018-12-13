/* 11790 - Murcia's Skyline */

#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n,c=1;
  ifstream in;
  ofstream out;
  //in.open("lis");
  //out.open("lis_o");
  cin>>t;
  while(t--){
    cin>>n;

    int h[n],w[n],lis[n],lds[n];

    for(int i=0;i<n;i++){
      cin>>h[i];
    }
    for(int i=0;i<n;i++)
      cin>>w[i];
    

    int inc_max=0,dec_max=0,inc_temp,dec_temp;
    for(int i=0;i<n;i++){
      inc_temp=dec_temp=lis[i]=lds[i]=w[i];
      for(int j=0;j<i;j++){
	if(h[i]<h[j]){
	  lis[i]=max(lis[i],lis[j]+inc_temp);
	}
	if(h[i]>h[j]){
	  lds[i]=max(lds[i],lds[j]+dec_temp);
	}
      }
      inc_max=max(inc_max,lis[i]);
      dec_max=max(dec_max,lds[i]);
    }
    
   
    
    
    cout<<"Case "<<c++<<". ";
    if(dec_max>=inc_max){
      cout<<"Increasing ("<<dec_max<<"). "<<"Decreasing ("<<inc_max<<")."<<endl;
    }
    else{
      cout<<"Decreasing ("<<inc_max<<"). "<<"Increasing ("<<dec_max<<")."<<endl;
    }
  }  
  return 0;
}
  
