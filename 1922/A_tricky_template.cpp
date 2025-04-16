#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string tricky_template(int length, string a, string b, string c){
    for (int i = 0; i < length; i++){
        if (a[i] != c[i] && b[i] != c[i]){
            return "YES";
        }
    }
    return "NO";
}

int main() {
    // Your code here
    int num_tests;

    cin >> num_tests;
    for (int i=0; i < num_tests; i++){
        string a, b, c;
        int length;
        cin >> length >> a >> b >> c;
        cout << tricky_template(length, a, b, c) << endl;
    }    

    return 0;
}


