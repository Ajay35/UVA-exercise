/* 11831 - Sticker Collector Robot */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,s,ori,x,y;
  ifstream in;
  ofstream out;
  //in.open("tick");
  //out.open("tick_o");
  while(cin>>n>>m>>s){

    if(n==0 && m==0 && s==0)
      break;
    
    char arr[n][m];
    char moves[s];
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	
	cin>>arr[i][j];
	// 1:north 2:south 3:east 4:west
	if(arr[i][j]!='*' && arr[i][j]!='.' && arr[i][j]!='#'){
	  //cout<<"found start:"<<i<<" "<<j<<endl;
	  if(arr[i][j]=='N')
	    ori=1;
	  else if(arr[i][j]=='S')
	    ori=2;
	  else if(arr[i][j]=='L')
	    ori=3;
	  else if(arr[i][j]=='O')
	    ori=4;
	  x=i;
	  y=j;
	}
      }
    }
    //cout<<"reading matrix"<<endl;
    for(int i=0;i<s;i++){
      cin>>moves[i];
    }
    //cout<<"reading dirs"<<endl;
    int c=0;
    for(int i=0;i<s;i++){
      if(moves[i]=='F'){
	//cout<<"F move"<<endl;
	if(ori==1 && x>0 && arr[x-1][y]!='#'){
	  //cout<<arr[x-1][y]<<endl;
	  if(arr[x-1][y]=='*'){
	    //cout<<"found"<<endl;
	    arr[x-1][y]='.';
	    c++;
	  }
	  x--;
	  //cout<<"ori:"<<ori<<" "<<x<<" "<<y<<endl;
	}
	if(ori==2 && x<n-1 &&  arr[x+1][y]!='#'){
	  //cout<<arr[x+1][y]<<endl;
	  if(arr[x+1][y]=='*'){
	    //cout<<"found"<<endl;
	    c++;
	    arr[x+1][y]='.';
	  }
	  x++;
	  //cout<<"ori:"<<ori<<" "<<x<<" "<<y<<endl;
	}
	if(ori==3 && y<m-1 && arr[x][y+1]!='#'){
	  //cout<<arr[x][y+1]<<endl;
	  if(arr[x][y+1]=='*'){
	    //cout<<"found"<<endl;
	    c++;
	    arr[x][y+1]='.';
	  }
	  y++;
	  //cout<<"ori:"<<ori<<" "<<x<<" "<<y<<endl;
	}
	if(ori==4 && y>0  && arr[x][y-1]!='#'){
	  //cout<<arr[x][y-1]<<endl;
	  if(arr[x][y-1]=='*'){
	    //cout<<"found"<<endl;
	    c++;
	    arr[x][y-1]='.';
	  }
	  y--;
	  //cout<<"ori:"<<ori<<" "<<x<<" "<<y<<endl;	  
	}
      }
      else if(moves[i]=='D'){
	//cout<<"D move"<<endl;
	if(ori==1){
	  ori=3;
	}
	else if(ori==2){
	  ori=4;
	}
	else if(ori==3){
	  ori=2;
	}
	else if(ori==4){
	  ori=1;
	}
      }
      else if(moves[i]=='E'){
	//cout<<"E move"<<endl;
	if(ori==1){
	  ori=4;
	}
	else if(ori==2){
	  ori=3;
	}
	else if(ori==3){
	  ori=1;
	}
	else if(ori==4){
	  ori=2;
	}
      }
    }
    //cout<<"done"<<endl;
    cout<<c<<endl;
  }
  return 0;
}
 
