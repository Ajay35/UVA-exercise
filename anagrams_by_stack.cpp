#include <bits/stdc++.h>
using namespace std;
void anagram(string str1,string str2,string stk,string res)
{
  if(str1.empty() && stk.empty())
  {
    for(int i=0;i<res.size();i++)
    {
      if(i!=res.size()-1)
	cout<<res[i]<<" ";
      else
	cout<<res[i];
    }
    cout<<"\n";
    return;
  }
  if(!str1.empty())
  {
    anagram(str1.substr(1),str2,str1[0]+stk,res+'i');
  }
  if(!str2.empty() && stk[0]==str2[0])
  {
    anagram(str1,str2.substr(1),stk.substr(1),res+'o');    
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string str1,str2;
  while(cin>>str1)
  {
    cin>>str2;
    cout<<"["<<endl;
    if(str1.size()==str2.size())
      anagram(str1,str2,"","");
    cout<<"]"<<endl;
  }
  return 0;
}
