// C program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll _mergeSort(int arr[], int temp[], int left, int right); 
ll merge(int arr[], int temp[], int left, int mid, int right); 

ll mergeSort(int arr[], int array_size) { 
	int* temp = (int*)malloc(sizeof(int) * array_size); 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

ll _mergeSort(int arr[], int temp[], int left, int right){ 
  ll  inv_count = 0; 
  int mid;
  if (right > left){ 
    mid = (right + left) / 2; 
    
    inv_count = _mergeSort(arr, temp, left, mid); 
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right); 
  } 
  return inv_count; 
} 
ll merge(int arr[], int temp[], int left, int mid, int right){ 
  int i, j, k;
  
  ll inv_count = 0; 
  
  i = left; 
  j = mid; 
  k = left; 
  while ((i <= mid - 1) && (j <= right)){
    if (arr[i] <= arr[j]) { 
      temp[k++] = arr[i++]; 
    } 
    else { 
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i); 
    } 
  } 
  while (i <= mid - 1) 
    temp[k++] = arr[i++]; 
  while (j <= right) 
    temp[k++] = arr[j++]; 
  
  for (i = left; i <= right; i++) 
    arr[i] = temp[i]; 
  
  return inv_count; 
} 

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t,n;
  ifstream in;
  ofstream out;
  //in.open("inv");
  //out.open("inv_o");
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    cout<<mergeSort(arr,n)<<endl;
  }
	return 0; 
} 
