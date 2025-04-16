// THIS IS BROKEN


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#include <unordered_set>


const int N = 3e5 + 10;
int monster_attack[N];
int monster_defence[N];
int locked_left[N];
int locked_right[N];
int creature_on_right[N];
int creature_on_left[N];
int damage[N];
unordered_set<int> alive;
unordered_set<int> alive2;


int calculate_battle(){
    //cout << "TEST" << endl;
    int kills = 0;
    // loop through every monster in alive:
    memset(damage, 0, sizeof(damage));
    for (int itr : alive){
        // Calculate Damage to creature
        int creature_left = creature_on_left[itr];
        int creature_right = creature_on_right[itr];
        damage[itr] = monster_attack[creature_left] + monster_attack[creature_right];
    }
    // Copy Alive to Alive2
    alive2.clear();
    for (int itr : alive){
        alive2.insert(itr);
    }
    for (int itr : alive2){

        int creature_left = creature_on_left[itr];
        int creature_right = creature_on_right[itr];

        if (damage[itr] > monster_defence[itr]){
            // H2: Dead
            alive.erase(itr);
            // Update Adjacencies:
            creature_on_right[creature_left] = creature_on_right[itr];
            creature_on_left[creature_right] = creature_on_left[itr];

            // If the creature was previously removed
            if (alive.find(creature_left) == alive.end()){
                if (locked_left[creature_left] == 1) {
                    alive.insert(creature_left);
                    //cout << "CREATURE ADDED LEFT:" << creature_left << endl;
                }
            }
            if (alive.find(creature_right) == alive.end()){
                if (locked_right[creature_right] == 1) {
                    alive.insert(creature_right);
                    //cout << "CREATURE ADDED RIGHT:" << creature_right << endl;
                }
            }

            locked_left[creature_right] = 0;
            locked_right[creature_left] = 0;
            kills++;
            //cout << "CREATURE DEAD:" << itr << endl;
        }
        else {
            // H2: Alive
            locked_left[creature_right] = 1;
            locked_right[creature_left] = 1;

            //cout << "CREATURE SURVIVE:" << itr << endl;
        }
    }

    for (int itr : alive){
        // Check if the creature is deadlocked
        if (locked_left[itr] == 1 && locked_right[itr] == 1){
            alive.erase(itr);
            //cout << "CREATURE REMOVED:" << itr << endl;
        }
    }
    return kills;
}

void clear_memory(){
    memset(monster_attack, 0, sizeof(monster_attack));
    memset(monster_defence, 0, sizeof(monster_defence));
    memset(locked_left, 0, sizeof(locked_left));
    memset(locked_right, 0, sizeof(locked_right));
    memset(creature_on_right, 0, sizeof(creature_on_right));
    memset(creature_on_left, 0, sizeof(creature_on_left));
    alive.clear();
}


int main() {
    // Your code here
    int num_tests;

    cin >> num_tests;
    for (int i=0; i < num_tests; i++){
        int num_monsters;
        clear_memory();
        
        cin >> num_monsters;
        for (int j = 0; j < num_monsters; j++) {
            cin >> monster_attack[j + 1];
        }
        for (int j = 0; j < num_monsters; j++) {
            cin >> monster_defence[j + 1];
        }
        
        for (int j = 1; j < num_monsters + 1; j++) {
            creature_on_right[j] = j+1;
            creature_on_left[j] = j-1;
            alive.insert(j);
        }

        int num_times = num_monsters;
        for (int j = 0; j < num_times; j++){
            cout << calculate_battle() << ' ';
        }
        cout << endl;
        //calculate_battle();
    }    

    return 0;
}

// IDEA: Simulate! But when a creature fails to kill, save it in a deadlock array