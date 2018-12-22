/* 924 - Spreading The News */

	
#include <bits/stdc++.h>
using namespace std;

int e,n,t,x;
vector<vector<int>> emp;
bool visited[2500];

int main(){
		ifstream in;
		ofstream out;
		//in.open("me");
		//out.open("meo");
		in>>e;
		
		emp.resize(e);
		
		for(int i=0;i<e;i++){
			in>>n;
			for(int j=0;j<n;j++){
				in>>x;
				emp[i].push_back(x);
			}
		}
			
		in>>t;
		
		
		while(t--){
			in>>x;
			memset(visited,0,sizeof(visited));
			visited[x]=1;
			queue<int> que;
			que.push(x);
			
			int ans_day=0,ans_emp=0,it=1;	
			
			while(!que.empty()){
				int temp=0;				
				int siz=que.size();
				while(siz--){
					int u=que.front();
					que.pop();
					//cout<<"vising:"<<u<<endl;
					for(int i=0;i<emp[u].size();i++){
						if(!visited[emp[u][i]]){
							//cout<<"visitin:"<<emp[u][i]<<endl;
							visited[emp[u][i]]=1;
							temp++;
							que.push(emp[u][i]);
						}
						/*else{
							//cout<<"already visited:"<<emp[u][i]<<endl;
						}*/
					}
					if(temp>ans_emp){
						ans_emp=temp;
						ans_day=it;
					}
				}
				it++;
			}
			if(ans_emp!=0)
				out<<ans_emp<<" "<<ans_day<<endl;
			else 
				out<<0<<endl;
		}
		
		return 0;
}