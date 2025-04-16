#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int closest_cities[N]; 
int distance_leftmost_city_to_index[N]; 
int distance_rightmost_city_to_index[N]; 


void calculate_closest_cities(int num_cities, vector<int> &cities) {
    memset(closest_cities, 0, sizeof(closest_cities));

    closest_cities[0] = 1;
    closest_cities[num_cities - 1] = num_cities - 2;
    for (int i = 1; i < num_cities - 1; i++) {
        int dist_a, dist_b;
        dist_a = cities[i] - cities[i - 1];
        dist_b = cities[i + 1] - cities[i];
        if (dist_a < dist_b) {
            closest_cities[i] = i - 1;
        } else {
            closest_cities[i] = i + 1;
        }
    }

    // Calculate Prefix Sum Arrays:
    distance_leftmost_city_to_index[0] = 0;
    for (int i = 1; i < num_cities; i++) {
        if (closest_cities[i - 1] == i) {
            distance_leftmost_city_to_index[i] = distance_leftmost_city_to_index[i - 1] + 1;
        } else {
            distance_leftmost_city_to_index[i] = distance_leftmost_city_to_index[i - 1] + (cities[i] - cities[i - 1]);
        }
    }


    distance_rightmost_city_to_index[num_cities - 1] = 0;
    for (int i = num_cities - 2; i >= 0; i--) {
        if (closest_cities[i + 1] == i) {
            distance_rightmost_city_to_index[i] = distance_rightmost_city_to_index[i + 1] + 1;
        } else {
            distance_rightmost_city_to_index[i] = distance_rightmost_city_to_index[i + 1] + (cities[i + 1] - cities[i]);
        }
    }

    return;
}


int min_coins_to_travel(int a, int b) {
    int coins = 0;

    // Travel Right
    if (a < b) {
        return distance_leftmost_city_to_index[b] - distance_leftmost_city_to_index[a];
    }

    // Travel Left
    if (a > b) {
        return distance_rightmost_city_to_index[b] - distance_rightmost_city_to_index[a];
    }

    return coins;
}


int main() {
    // Your code here
    int num_tests;

    cin >> num_tests;
    for (int i=0; i < num_tests; i++){
        int num_cities;
        vector<int> cities;

        cin >> num_cities;
        for (int j = 0; j < num_cities; j++) {
            int a;
            cin >> a;
            cities.push_back(a);
        }

        calculate_closest_cities(num_cities, cities);
        /*for (int j = 0; j < num_cities; j++) {
            cout << closest_cities[j] << " ";
        }
        for (int j = 0; j < num_cities; j++) {
            cout << distance_leftmost_city_to_index[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < num_cities; j++) {
            cout << distance_rightmost_city_to_index[j] << " ";
        }*/

        int num_cases;
        cin >> num_cases;
        for (int j = 0; j < num_cases; j++) {
            int a, b;
            cin >> a >> b;
            cout << min_coins_to_travel(--a, --b) << endl;
        }

    }    

    return 0;
}



int min_coins_to_travel_old(vector<int> &cities, int a, int b) {
    int loc = a;
    int coins = 0;

    // Travel Right
    while (loc < b) {
        if (closest_cities[loc] == loc + 1) {
            coins++;
        } else {
            coins += cities[loc + 1] - cities[loc];
        }
        loc++;
    }

    // Travel Left
    while (loc > b) {
        if (closest_cities[loc] == loc - 1) {
            coins++;
        } else {
            coins += cities[loc] - cities[loc - 1];
        }
        loc--;
    }

    return coins;
}