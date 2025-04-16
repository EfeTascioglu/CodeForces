#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>


const int N = 2e5 + 10;
int n, a[N];


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
    }

    return 0;
}




int main() {
    // Your code here
    int num_lines;
    vector<string> lines;
    cin >> num_lines;
    for (int i = 0; i < num_lines; i++) {
        string line;
        cin >> line;
        lines.push_back(line);
    }    

    return 0;
}

