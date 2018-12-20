/*  11953 - Battleships */

#include <bits/stdc++.h>

using namespace std;

int t,n,cs=1;
char grid[100][100];
bool visited[100][100];

void dfs(int i,int j){
	
	if(i<0 || i>=n || j<0 || j>=n || visited[i][j] || grid[i][j]=='.')
		return;
	visited[i][j]=true;
	dfs(i+1,j);
	dfs(i,j+1);
	dfs(i-1,j);
	dfs(i,j-1);
}

int main(){
	
	ifstream in;
	ofstream out;
	//in.open("b");
	//out.open("bo");
	
	cin>>t;
	
	while(t--){
		cin>>n;
		memset(visited,0,sizeof(visited));

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>grid[i][j];
			}
		}
		int c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!visited[i][j] && grid[i][j]=='x'){
					dfs(i,j);
					c++;
				}
			}
		}
		//cout<<"Case "<<cs++<<": "<<c<<endl;
		cout<<"Case "<<cs++<<": "<<c<<endl;
		
	}
	return 0;
}