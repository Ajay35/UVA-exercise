/* 10653 - Bombs! NO they are Mines!! */

#include <bits/stdc++.h>
using namespace std;

int R,C,rows,r,c,sx,sy,dx,dy,n;
bool visited[1000][1000];
int dis[1000][1000];

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

bool isSafe(int x,int y){
	
	if(x>=0 && x<R && y>=0 && y<C && !visited[x][y])
		return true;
	return false;
}

int main(){
	
	ifstream in;
	ofstream out;
	//in.open("bomb");
	//out.open("bom_o");
	while(cin>>R>>C){
		
		if(R==0 && C==0)
			break;
		memset(visited,0,sizeof(visited));
		memset(dis,0,sizeof(dis));
		cin>>rows;
		for(int i=0;i<rows;i++){
			cin>>r>>n;
			for(int j=0;j<n;j++){
				cin>>c;
				visited[r][c]=1;
			}
		}
		cin>>sx>>sy;
		cin>>dx>>dy;
		visited[sx][sy]=1;
		dis[sx][sy]=0;
		
		queue<pair<int,int>> que;
		que.push(make_pair(sx,sy));
		
		while(!que.empty()){
			
			pair<int,int> temp=que.front();
			que.pop();
			
			for(int i=0;i<4;i++){
				int t1=temp.first+dr[i],t2=temp.second+dc[i];
				if(isSafe(t1,t2)){
					visited[t1][t2]=1;
					dis[t1][t2]=1+dis[temp.first][temp.second];
					que.push(make_pair(t1,t2));
				}
			}
		}
		cout<<dis[dx][dy]<<endl;
	}
	
	return 0;
}