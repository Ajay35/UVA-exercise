/*  231 - Testing the CATCHER */

#include <bits/stdc++.h>
using namespace std;
int c=1;
int main(){
  ifstream in;
  ofstream out;
  in.open("lis");
  out.open("lis_o");
  vector<int> input;
  while (true){
    int value;
    in >> value;
    if (in.eof()){
      break;
    }
    input.push_back(value);
    if(value!=-1)
      continue;
  
  vector<int> parent;
  parent.resize(input.size());
  vector<int> active_sequence_ends;
  vector<int> active_sequence_indices;
  
  // Initialize
  parent[0] = -1;
  active_sequence_ends.push_back(input[0]);
  active_sequence_indices.push_back(0);
  
  for(unsigned int i = 1; i < input.size(); i++){
    unsigned int index = lower_bound(active_sequence_ends.begin(), active_sequence_ends.end(), input[i]) - active_sequence_ends.begin();
    
    if (index == active_sequence_ends.size()){
      parent[i] = active_sequence_indices[active_sequence_indices.size() - 1];
      active_sequence_ends.push_back(input[i]);
      active_sequence_indices.push_back(i);
      }
    else{
      if(index == 0)
	parent[i] = -1;
      else
	parent[i] = active_sequence_indices[index - 1];
      active_sequence_ends[index] = input[i];
      active_sequence_indices[index] = i;
    }
  }
  out<<"Test #"<<c++<<":"<<endl;
  out <<"  maximum possible interceptions: "<<active_sequence_ends.size() << endl;
  out<<endl;
  input.clear();
  active_sequence_ends.clear();
  active_sequence_indices.clear();
  }
  return 0;
}
