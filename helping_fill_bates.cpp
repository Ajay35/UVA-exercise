#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string str1,str2;
  cin>>str1;
  int q;
  cin>>q;
  while(q--)
  {
    cin>>str2;
    int arr[str2.size()];
    int i=0,j=0,k=0;
    bool f=false;
    while(i<str1.size())
    {
      if(str1[i]==str2[j])
      {
	arr[k]=i;
	i++;
	j++;
	k++;
	if(j==str2.size())
	  f=true;
      }
      else
      {
	i++;
      }
    }
    if(f)
      cout<<"Matched "<<arr[0]<<" "<<arr[str2.size()-1]<<endl;
    else
      cout<<"Not matched"<<endl;
  }
  
  return 0;
}
