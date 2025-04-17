#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
const int N = 2e5 + 10;
int T; // Num cases
int n; // Num Rows
int A[N];
int B[N];
int C[N];


void sort_an_array_bucket(){
    for (int i = 1; i <= n; i++){
        C[A[i]] = B[i];
    }
}


int main() 
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &B[i]);
        }
        sort_an_array_bucket();

        for (int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << endl;
        for (int i = 1; i <= n; i++){
            cout << C[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
