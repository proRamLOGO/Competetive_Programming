#include<bits/stdc++.h>
using namespace std;

void solve(){
  static int c = 1;
  int n;
  scanf("%d",&n);
  vector<int> arr(n),ans(n);
  for(int &i: arr)scanf("%d",&i);
  for(int i = 0; i < (1 << n); ++i){
    int left = 0;
    int right = 0;
    bool pos1 = true;
    bool pos2 = true;
    for(int j = 0; j < n; ++j){
      if((i>>j)&1)left++;
      else right++;
      if(abs(left-right) > 1){
        pos1 = false;
        break;
      }
    }
    if(!pos1)continue;
    for(int j = 0; j < n; ++j){
      if((i >> (arr[j]-1)) & 1)left--;
      else right--;
      if(abs(left-right) > 1){
        pos2 = false;
        break;
      }
    }
    if(pos2){
      printf("Case #%d: ",c++);
      for(int j = 0; j < n; ++j){
        if((i>>j)&1)printf("L");
        else printf("R");
      }
      printf("\n");
      return;
    }
  }
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--)solve();
  return 0;
}