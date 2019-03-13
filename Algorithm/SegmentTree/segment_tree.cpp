/* C++ program for Segment Tree */
#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

void build(vector<int> arr, int l, int r, int pos, vector<int>&vec) {
  if(l==r) {
    vec[pos] = arr[l];
  }
  else if(l < r) {
    int m = l + (r - l) / 2;
    build(arr, l, m, 2*pos+1,vec);
    build(arr, m + 1, r, 2 * pos + 2, vec);
    vec[pos]=min(vec[pos*2+1],vec[pos*2+2]);
    // printf("%d %d %d %d\n", l,m,m+1,r); partition segment array
  }
}

void update(vector<int>&arr, int l, int r, int pos, vector<int>&vec, int val, int ind) {
  if(l==r) {
    vec[pos] = val;
    arr[ind] = val;
  }
  else if(l < r) {
    int m = l + (r - l) / 2;
    if(l <= ind && ind <= m)
        update(arr, l, m, 2*pos+1,vec, val, ind);
    else
        update(arr, m + 1, r, 2 * pos + 2, vec, val, ind);
    vec[pos]=min(vec[pos*2+1],vec[pos*2+2]);
  }
}

int query(vector<int> vec, int l, int r, int pos, int p, int q) {
    if(p <= l && q >= r) {
        return vec[pos];
    } else if (l>q || p>r) {
        return MAX;
    } else {
    int m = l + (r - l) / 2;
    int a = query(vec, l, m, 2 * pos + 1, p, q);
    int b = query(vec, m + 1, r, 2 * pos + 2, p, q);
    return min(a, b);
  }
}

void printArray(vector<int> A, int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) 
    cin>>arr[i];
    int arr_size = n;
    printf("Given array is \n");
    printArray(arr, arr_size);
    int log_lim = ceil(log(n)/log(2))+1;
    int vec_size = pow(2, log_lim)-1;
    vector<int>vec(vec_size, MAX);
    build(arr, 0, arr_size - 1, 0, vec);

    printf("\nSegment array is \n");
    printArray(vec, vec.size());

    int Q;
    cin>>Q;
    for (int i = 0; i < Q; i++) {
      int a,b;
      scanf("%d%d", &a,&b);
      printf("range between %d %d ", a, b);
      a = query(vec, 0, arr_size, 0, a, b);
      printf("Min is: %d\n", a);
  }
  // update function
  int U;
  cin>>U;
  for(int i=0;i<U;i++) {
      int ind,val;
      cin>>ind>>val;
      update(arr, 0, arr_size - 1, 0, vec, val, ind);
      cout << "updated array: \n";
      printArray(arr, arr.size());
      // search range 
      int a,b;
      cin>>a>>b;
      printf("range between %d %d ", a, b);
      a = query(vec, 0, arr_size, 0, a, b);
      printf("Min is: %d\n", a);
  }
  
  return 0;
}
