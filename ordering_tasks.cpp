/* 10305 - Ordering Tasks  */

#include <bits/stdc++.h>
using namespace std;

int n,e,a,b;

vector<int> edge[101];
stack<int> stk;
bool visited[101];

void topo(int i){

	visited[i]=1;
	
	for(int j=0;j<edge[i].size();j++){
		if(!visited[edge[i][j]]){
			topo(edge[i][j]);
		}
	}
	stk.push(i);
}

int main(){
	
	while(cin>>n>>e){
		if(n==0 && e==0)
			break;
		
		for(int i=0;i<e;i++){
			cin>>a>>b;
			edge[a].push_back(b);
		}
		memset(visited,0,sizeof(visited));
		if(e>0){
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				topo(i);
			}
		}
		while(!stk.empty()){
			cout<<stk.top()<<" ";
			stk.pop();
		}
		cout<<endl;
		}
		else
		{
			for(int i=n;i>=1;i--)
				cout<<i<<" ";
			cout<<endl;
		}
		
	}
	return 0;
}