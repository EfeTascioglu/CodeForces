#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
// 2e8 calculations per second

const int N = 3e5 + 10;
int stick_sizes[N] = {0};

long long nChoosek(int n, int k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for(int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}



long long num_permutations_of_sticks(int num_sticks, vector<int> &sticks) {
    long long num_permutations = 0;
    
    memset(stick_sizes, 0, sizeof(stick_sizes));

    for (int i = 0; i < num_sticks; i++) {
        stick_sizes[sticks[i]]++;
    }
    
    int smaller_sticks = 0;
    for (int i = 0; i <= num_sticks; i++) {
        smaller_sticks += stick_sizes[i];
        if (stick_sizes[i] < 2) {
            continue;
        }
        int num_other_sticks = smaller_sticks - stick_sizes[i];

        num_permutations += nChoosek(stick_sizes[i], 3);

        num_permutations += nChoosek(stick_sizes[i], 2) * num_other_sticks;
    }
    return num_permutations;
}


int main() {
    // Your code here
    int num_tests;

    cin >> num_tests;
    for (int i=0; i < num_tests; i++){
        int num_inputs;
        vector<int> inputs;

        cin >> num_inputs;
        for (int j = 0; j < num_inputs; j++) {
            int a;
            cin >> a;
            inputs.push_back(a);
        }

        cout << num_permutations_of_sticks(num_inputs, inputs) << endl;
    }    

    return 0;
}

