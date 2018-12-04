#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    if(n==0)
      break;
    int arr[n];
    bool all_negative=true;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if(arr[i]>0)
	all_negative=false;
    }
    if(all_negative)
    {
      cout<<"Losing streak."<<endl;
      continue;
    }
    int max_so_far=INT_MIN,maxx=0;

    for(int i=0;i<n;i++)
    {
      maxx=maxx+arr[i];
      if(max_so_far<maxx)
      {
	max_so_far=maxx;
      }
      if(maxx<0)
	maxx=0;
    }
    cout<<"The maximum winning streak is "<<max_so_far<<"."<<endl;
  }
    
  return 0;
}
