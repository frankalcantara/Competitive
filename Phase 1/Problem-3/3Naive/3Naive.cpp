#include <iostream>  // Includes input/output stream for standard input/output
#include <vector>    // Includes the vector library for dynamic arrays

using namespace std;  // Allows usage of standard library objects without prefixing with std::

int main() {
    // Hardcoded input values
    int n = 6, q = 4;  // n is the size of the inventory vector, q is the number of adjustments
    vector<int> inventory = { 10, 3, 5, 6, 8, 2 };  // Vector to store the initial inventory values
    vector<pair<int, int>> adjustments = { {3, 1}, {-4, 0}, {2, 3}, {-3, 4} };  // Vector of pairs representing adjustments: {adjustment_value, index}

    // Initial sum of even numbers
    int even_sum = 0;  // Variable to store the sum of even inventory values
    for (int i = 0; i < n; ++i)  // Loop through each element in the inventory vector
        if (!(inventory[i] & 1)) even_sum += inventory[i];  // Check if the value is even using bitwise AND, add to even_sum if even

    // Process adjustments
    for (int i = 0; i < q; ++i) {  // Loop through each adjustment
        int adj = adjustments[i].first, idx = adjustments[i].second;  // Extract adjustment value and index from the current pair
        if (!(inventory[idx] & 1)) even_sum -= inventory[idx];  // If current inventory value at index is even, subtract it from even_sum
        inventory[idx] += adj;  // Apply the adjustment to the inventory at the given index
        if (!(inventory[idx] & 1)) even_sum += inventory[idx];  // If the updated value at index is even, add it to even_sum
        cout << even_sum << '\n';  // Output the current sum of even numbers after the adjustment
    }
}
