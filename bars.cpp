#include<bits/stdc++.h>
using namespace std;
int t,l,p,found=false;
void isPossible(int i,int cur,int arr[]){
  //cout<<"current is:"<<cur<<endl;
  if(i==p){
    if(cur==l){
      found=true;
    }
    return;
  }
  isPossible(i+1,cur,arr);
  if((arr[i]+cur)<=l){
    isPossible(i+1,cur+arr[i],arr);
  }
  return;
}

int main(){
  cin>>t;
  while(t--){
    cin>>l>>p;
    int arr[p];
    for(int i=0;i<p;i++)
      cin>>arr[i];
    isPossible(0,0,arr);
    if(found){
      cout<<"YES"<<endl;
      found=false;
    }
    else{
      cout<<"NO"<<endl;
    }
   
  }
  return 0;
}
