#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
//const int N = 2e5 + 10;
int T; // Num cases
long long a;
long long b;
long long r;

long long two_power(int k){
    return (1ll << (k));
}

long long xor_distance(long long a, long long b, long long r){
    long long dist = a - b;
    bool first_time = true;
    for (int i = 59; i >= 0; i--){ // Max Exponent Value
        if (!(((b >> i & 1) == 0) && ((a >> i & 1) == 1))) { // swappable bit
            continue;
        }

        if (a >= two_power(i)){
            if (first_time){ // This is the largest swappable bit. If we swap this B becomes larget than A. Don't want that.
                first_time = false;
                continue;
            }
        }

        if (r >= two_power(i)){ // Range is great enough to flip this bit.
            r -= two_power(i);
            dist -= two_power(i) * 2;
        }
    }
    return dist;
}


int main() 
{
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &a, &b, &r);
        if (b > a){
            swap(a, b);
        }
        //xor_distance(a, b, r);
        cout << xor_distance(a, b, r) << endl;
    }
    return 0;
}
