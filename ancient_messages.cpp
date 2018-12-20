/* 1103 - Ancient Messages */

#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int h,w,p,q;
char arr[200][50];
bool visited[200][200];
vector<string> img;

string hex_char_to_bin(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}
void dfs(int i,int j){
	if(i<0 || j<0 || i>=p || j>=q || visited[i][j] || img[i][j]!='0')
		return;
	visited[i][j]=true;
	dfs(i+1,j);
	dfs(i,j+1);
	dfs(i-1,j);
	dfs(i,j-1);
	dfs(i+1,j+1);
	dfs(i-1,j-1);
	dfs(i-1,j+1);
	dfs(i+1,j-1);
}

int main(){
	
	ifstream in;
	ofstream out;
	
	in.open("img");
	out.open("img_o");
	
	while(in>>h>>w){
		if(h==0 && w==0)
			break;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				in>>arr[i][j];
			}
		}
		memset(visited,false,sizeof(visited));
		img.resize(h);
		for(int i=0;i<h;i++){
			img[i]="";
			for(int j=0;j<w;j++){
				//cout<<"aa"<<endl;
				img[i]+=hex_char_to_bin(arr[i][j]);
			}
		}
		
		
		p=h,q=4*w;
		int c=0;
		for(int i=0;i<img.size();i++){
			for(int j=0;j<img[i].size();j++){
				if(img[i][j]=='0' && !visited[i][j]){
					dfs(i,j);
					c++;
				}
			}
		}
		/*cout<<"-----------------"<<endl;
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				cout<<visited[i][j];
			}
			cout<<endl;
		}*/
		c--;
		if(c==0){
			
		}
		else if(c==1){
			
		}
	}
	return 0;
}