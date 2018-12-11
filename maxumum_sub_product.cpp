#include<bits/stdc++.h>

using namespace std;

int main()
{
  ifstream in;
  ofstream out;
  //in.open("prod");
  //out.open("prodo");
  vector<int> mx;

        int i=0,n;

        while((cin>>n))
	  {
	    if(n!=-999999){
	      mx.push_back(n);
	      continue;
	    }
	    long sum=1,mxV=-999999;
	    
	    for(int j=0;j<mx.size();j++)
	      {
		sum=1;
		for(int k=j;k<mx.size();k++){
		  sum=sum*mx[k];
		}
		if(mxV<sum)mxV=sum;
	      }
	    cout<<mxV<<endl;
	    mx.clear();
	  }
	return 0;
}
