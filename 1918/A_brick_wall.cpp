#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
int n; 
int m;


int max_stability(int n, int m){
    return (m / 2) * n;
}



int main() 
{
    int T; // Num cases
    scanf("%d", &T);
    while (T--) {
      scanf("%d%d", &n, &m);
      cout << max_stability(n, m) << endl;
    }
    return 0;
}
