#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	//in.open("coin.txt")	;
	//out.open("coin_o");
	int t,n,c;
	cin>>t;
	while(t--){
		cin>>n>>c;
		int coins[c],dp[10001];
		for(int i=0;i<c;i++){
			cin>>coins[i];
		}
		for (int i = 0; i <=10000; ++i)
		{
			dp[i]=INT_MAX;
		}
		dp[0]=0;

		for(int i=0;i<c;i++){
			for(int j=10000-coins[i];j>=0;j--){
				if(dp[j]!=INT_MAX && dp[j]+1<dp[j+coins[i]]){
					dp[j+coins[i]]=dp[j]+1;
				}
			}
		}
		for(int i=n;i<=10000;i++){
			if(dp[i]!=INT_MAX){
				cout<<i<<" "<<dp[i]<<endl;
				break;
			}
		}

	}
	return 0;
}