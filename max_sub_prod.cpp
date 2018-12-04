#include<bits/stdc++.h>
using namespace std;
long prod(vector<int> arr)
{
  long prod=1;



  return prod;
}
int main()
{
  vector<int> arr;
  int x;
  while(cin>>x)
  {
    if(x!=-999999)
    {
      arr.push_back(x);
      continue;
    }

    cout<<prod(arr)<<endl;

    arr.clear();
  }
  
  return 0;
}
