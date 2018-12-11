/* 12405 - Scarecrow */

#include <bits/stdc++.h>
using namespace std;
int t,n,c,cs=1;
char field[99];
int main(){

  //ifstream in;
  //ofstream out;
  //in.open("scarec");
  //out.open("scare_o");
  cin>>t;

  while(t--){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>field[i];
    }
    c=0;
    for(int i=0;i<n;i++){
      if(field[i]=='.'){
	i+=2;
	c++;
      }
    }
    cout<<"Case "<<cs++<<": "<<c<<endl;    
  }
  return 0;
}
