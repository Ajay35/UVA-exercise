/* 12210 - A Match Making Problem */
#include <bits/stdc++.h>
using namespace std;
int b,s;
int main(){
  int cs=1;
  ifstream in;
  ofstream out;
  //in.open("mat");
  //out.open("mat_o");
  while(cin>>b>>s){
    if(b==0 && s==0)
      break;

    int ba[b],sp[s];

    for(int i=0;i<b;i++)
      cin>>ba[i];
    for(int i=0;i<s;i++)
      cin>>sp[i];

    sort(ba,ba+b);
    sort(sp,sp+s);

    if(b==s){
      cout<<"Case "<<cs++<<": "<<0<<endl;
    }
    else if(b>s){
      cout<<"Case "<<cs++<<": "<<b-s<<" "<<ba[0]<<endl;
    }
    else if(s>b){
      cout<<"Case "<<cs++<<": "<<0<<endl;
    }
  }
  return 0;
}
