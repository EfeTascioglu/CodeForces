#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
// Max Number of operations = 4e8

int T; // Num cases
int n; // Array length
const int N = 2e5 + 10; // Max Array Length
long long a[N]; // Array
long long cost_to_end_at_val[N];
long long prefix_sum_array[N];
deque<int> place_to_check;

//! Incorrect Function
bool check_solution_greedy(long long max_cost) {
    // O(n) function. Single pass
    long long cost_of_block = 0;
    long long cost_of_segment = 0;
    for (int i = 0; i < n; i++) {
        long long element = a[i];
        cost_of_segment += element;
        if (cost_of_segment > max_cost) {
            cost_of_segment = 0;
            cost_of_block += element;
        }
    }
    return cost_of_block <= max_cost;
}

void calculate_prefix_sum(){
    // O(n) function. Single pass
    //* change to 1 indexed array.
    prefix_sum_array[0] = 0;
    for (int i = 1; i <= n; i++){
        prefix_sum_array[i] = prefix_sum_array[i - 1] + a[i-1];
    }
    // End on a 0 for easy dp solution 
    a[n] = 0;
    prefix_sum_array[n + 1] = prefix_sum_array[n];
}

bool check_solution_dp(long long max_cost) {
    // O(n) function. Double Pass.
    /**
     ** Logic: Find the minimum cost to get to any index. Store this in a stack-queue (need to be able to pop both the start and the end).
     ** When adding a new value to the dp array, if it is lower than any previous values, we can remove those:
     ** This is because the new block has both lower blocking cost and is to the right of previous values.max_cost
     ** Thus, our stack-queue will be monotonically increasing, allowing us to check values from the end, and thus avoid ever checking the same value twice.
     ** i.e. In total throughout the entire process, it will be passed through once O(n). We also pass through the adding of values once O(n).
    */
    cost_to_end_at_val[0] = 0;
    place_to_check.clear();
    place_to_check.push_back(0);

    for (int i = 1; i <= n + 1; i++) {
        // H2: Pick the first element we can in the queue. Since the queue will be monotonic, the first element will be the best one to pick.
        long long cost_of_segment = prefix_sum_array[i-1] - prefix_sum_array[place_to_check.front()];
        while (cost_of_segment > max_cost) {
            place_to_check.pop_front();
            cost_of_segment = prefix_sum_array[i-1] - prefix_sum_array[place_to_check.front()];
        }
        // Found the cheapest previous block cost!
        long long cost_of_block = cost_to_end_at_val[place_to_check.front()] + a[i -1];
        // H2: Add to queue: Remove all elements that are greater than the current element, and add ours to the end of the queue. 
        while (!place_to_check.empty() && cost_to_end_at_val[place_to_check.back()] >= cost_of_block) {
            place_to_check.pop_back();
        }
        place_to_check.push_back(i);
        cost_to_end_at_val[i] = cost_of_block;
    }
    return cost_to_end_at_val[n + 1] <= max_cost;
}




long long min_cost_blocking() {
    calculate_prefix_sum();
    const long long max_solution = 1e14;

    long long high = max_solution;
    long long low = 0;
    long long mid;
    long long min_cost = -1;

    while (low < high) {
        mid = (low + high) / 2;
        // If we can solve this with cost mid, we might be able to solve with lower
        if (check_solution_dp(mid)) {
            min_cost = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return min_cost;
}


// This question is "monotonistic". A solution that solves the problem with cost = c, will also solve for cost = c + 1
// This means we can binary search the max cost.

// This is a question where finding the cost is extremely difficult, but checking a cost is easi(er). 

int main() 
{    
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[j]);
        }
        long long result = min_cost_blocking();
        cout << result << endl;
    }
    return 0;
}
