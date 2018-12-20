#include<bits/stdc++.h>
using namespace std;

int chains[50000];

int dfs(int i,int arr[],bool visited[]){
	
	visited[i]=true;
	int len=0;
	if(arr[i]!=-1 && !visited[arr[i]])
		len+=1+dfs(arr[i],arr,visited);	
	visited[i]=false;
	return chains[i]=len;
}

int main(){
	ifstream in;
	//in.open("email");
	ofstream out;
	//out.open("email_o");
	ios_base::sync_with_stdio(0);
	
	int t,m,a,b,cs=1;
	cin>>t;
	
	while(t--){
		memset(chains,-1,sizeof(chains));
		cin>>m;
		int arr[m];
		for(int i=0;i<m;i++){
			cin>>a>>b;
			arr[a-1]=b-1;
		}
		
		int longest=INT_MIN,ans;
		for(int i=0;i<m;i++){
			bool visited[m];
			memset(visited,false,sizeof(visited));
			int temp;
			//cout<<"temp:"<<temp<<endl;
			if(chains[i]==-1){
				dfs(i,arr,visited);
			}
			if(chains[i]>longest){
				longest=chains[i];
				ans=i+1;
			//	cout<<"answer:"<<ans<<endl;
			}
		}
		
		/*for(int i=0;i<m;i++){
			cout<<chains[i]<<" ";
		}*/
		//cout<<"\n";
		cout<<"Case "<<cs++<<": "<<ans<<endl;
	}
	return 0;
}