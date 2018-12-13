#include <bits/stdc++.h>
using namespace std;
int c=0;
// Function to find length of longest decreasing subsequence
int LDS(vector<int> arr, int i, int n, int prev){
  if (i == n){
    c++;
    cout<<"combination:"<<c<<endl;
    cout<<"finished"<<endl;
    return 0;
  }  
  int excl = LDS(arr, i + 1, n, prev);
  
  int incl = 0;
  if (arr[i] < prev)
    incl = 1 + LDS(arr, i + 1, n, arr[i]);

  return max(incl, excl);
}

int main(){
  ifstream in;
  ofstream out;
  int x;
  in.open("lis");
  out.open("lis_o");
  vector<int> arr;
  while(in>>x){
    arr.push_back(x);
  }
  cout<<"calling function"<<endl;
  out << "Length of LDS is " << LDS(arr, 0, arr.size(), INT_MAX);
  return 0;
}
