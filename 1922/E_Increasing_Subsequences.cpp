// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
LL n;

void increasing_subsequences(long long N){
    bool first_time = true;
    vector<int> output;
    for (int i = 60; i > -1; i--){
        if (N >> i){ // N >= 2^i
            if (first_time) {
                for (int j = 1; j < i + 1; j++){
                    //cout << j << ' ';
                    output.push_back(j);
                }
                first_time = false;
            }
            else {
                //cout << i + 1 << ' ';
                output.push_back(i+1);
            }
            //cout << "|||" << i << " " << N << endl;
            N -= 1ll << i;
        }
    }
    cout << output.size() << endl;
    for (int i: output){
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    // Write C++ code here
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        increasing_subsequences(n);
    }

    return 0;
}