/* 11906 - Knight in a War Grid */

#include <bits/stdc++.h>
using namespace std;

ifstream in;
ofstream out;


int r, c, m, n, w,cs=1;
int mat [100 + 2] [100 + 2];


int main ()
{
  //in.open("war");
  //out.open("war_o");
  int testCases;
  cin>>testCases;
  int cases = 0;
    
    while (testCases--){
 
       
	memset(mat,0,sizeof(mat));
	cin>>r>>c>>m>>n>>w;
       
 
        map<pair<int,int>,bool> waterMap;
 
        for (int i=0;i<w;i++){
            int a,b;
	    cin>>a>>b;
            waterMap [make_pair(a, b)] = true;
        }
	
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
	
        map<pair<int,int>,bool> visited;
        visited[make_pair(0,0)]=true;
	
        mat[0][0]=0;
	
        int dr[8]={-m,-m,m,m,-n,n,-n,n};
        int dc[8]={n,-n,n,-n,m,m,-m,-m};
	
        while (!q.empty()){
	  pair<int,int> pop=q.front();
	  q.pop();
	  
	  int newX, newY;
	  set<pair<int, int> > distinct;
	  
	  for(int i=0;i<8;i++){
	    newX=dr[i]+pop.first;
	    newY=dc[i]+pop.second;
	    distinct.insert(make_pair(newX, newY));
	  }
	  
	  for(set<pair<int,int>>::iterator it=distinct.begin();it!=distinct.end();it++){
	    pop=*it;
	    newX=pop.first;
	    newY=pop.second;
            
	    if(newX>=0 && newX<r && newY>=0 && newY<c && !waterMap[make_pair(newX, newY)]) {
	      mat [newX] [newY]++;
	      
	      if(!visited[make_pair(newX, newY)]){
		visited[make_pair(newX, newY)]=true;
		q.push(make_pair(newX, newY));
	      }	      
	    }
	  }
        }
	
        int cntEven = 0, cntOdd = 0;
	
        for(int i=0;i<r;i++){
	  for(int j=0;j<c;j++){
	    if(mat[i][j] || (!i && !j)){
	      if(mat[i][j]%2)
		cntOdd++;
	      else
		cntEven++;
	    }
	  }
        }
	
        cout<<"Case "<<cs++<<": "<<cntEven<<" "<<cntOdd<<"\n";
    }
 
    return 0;
}
 
