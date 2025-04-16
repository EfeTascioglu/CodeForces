#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;
int positive_array[N][N][N];
int negative_array[N][N][N]; 
int n; 
int input_array[N];
int m;


int num_operations(int n, int m){
  
  memset(positive_array, 0x3f, sizeof positive_array);
  memset(negative_array, 0x3f, sizeof negative_array);
  // Initial Setting:
  for (int i = 0; i < n; i++){
    for (int j = 1; j <= m; j++){
      positive_array[i][i][j] = input_array[i] != j;
      negative_array[i][i][j] = input_array[i] == j;
    }
  }
  
  // Update Step:
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      for (int k = 1; k <= m; k++){
        int ops;
        
        for (int div_start = l; div_start <= r; div_start++){
          // Case 1: make both subsequences 1:
          ops = positive_array[l][div_start][k] + positive_array[div_start+1][r][k];
          positive_array[l][r][k] = min(positive_array[l][r][k], ops);
          
          // Cost to make opposite:
          ops = negative_array[l][div_start][k] + negative_array[div_start+1][r][k];
          negative_array[l][r][k] = min(negative_array[l][r][k], ops);
          positive_array[l][r][k] = min(positive_array[l][r][k], ops + 1); //(Handled Below)
          
          // Flip one subsequence:
          // ops = positive_array[l][div_start][k] + negative_array[div_start+1][r][k] + 1;
          // positive_array[l][r][k] = min(positive_array[l][r][k], ops);

          // ops = negative_array[l][div_start][k] + positive_array[div_start+1][r][k] + 1;
          // positive_array[l][r][k] = min(positive_array[l][r][k], ops);
        }
        
        for (int other_k = 1; other_k <= m; other_k++){
          negative_array[l][r][other_k] = min(negative_array[l][r][other_k], positive_array[l][r][k] + (other_k == k));
        }
      }
      
      
    }
  }
  // for (int i = 0; i < n-1; i++){
  //   printf("%d ", negative_array[i][i+1][2]);
  // }
  // printf("\n");
  // printf("%d\n", negative_array[5][7][2]);
  // printf("%d\n", negative_array[4][7][2]);
  // printf("%d\n", positive_array[4][7][3]);
  //printf("%d\n", negative_array[4][7][3]);
  int min_val = 100000;
  for (int k = 1; k <= m; k++){
    min_val = min(min_val, positive_array[0][n-1][k]);
  }
  return min_val;
}




int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) {
      scanf("%d%d", &n, &m);
      for (int i = 0; i < n; i++) {
        scanf("%d", &input_array[i]);
      }
      cout << num_operations(n, m) << endl;
    }
    return 0;
}
