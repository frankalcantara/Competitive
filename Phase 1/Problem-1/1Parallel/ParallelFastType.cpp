#include <iostream>
#include <vector>
#include <numeric>
#include <execution>  // Necessary for execution policies in reduce

using namespace std;

// Aliases to reduce typing of long types
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using exec_seq = execution::sequenced_policy; // Alias for execution::seq

// Helper function to print the results in a formatted way.
void printResult(const vi& humidity, const vvi& adjustments, const vll& result) {
    // Prints the initial humidity and the adjustments.
    cout << "Input: humidity = [";
    for (size_t i = 0; i < humidity.size(); ++i) {
        cout << humidity[i] << (i < humidity.size() - 1 ? ", " : "");
    }
    cout << "], adjustments = [";
    for (size_t i = 0; i < adjustments.size(); ++i) {
        cout << "[" << adjustments[i][0] << "," << adjustments[i][1] << "]" << (i < adjustments.size() - 1 ? ", " : "");
    }
    cout << "]\n";

    // Prints the result after each adjustment.
    cout << "Output: ";
    for (auto res : result) {  // Using auto for automatic type deduction
        cout << res << " ";
    }
    cout << "\n\n";
}

int main() {
    // Example 1
    vi humidity1 = { 45, 52, 33, 64 };  // Initial humidity vector.
    vvi adjustments1 = { {5,0}, {-20,1}, {-14,0}, {18,3} };  // Adjustments vector.

    // Create a vector to store the results, reserving enough space to avoid unnecessary reallocations.
    vll result1;
    result1.reserve(adjustments1.size());

    // Iterates over each provided adjustment.
    for (const auto& adjustment : adjustments1) {
        int value = adjustment[0];  // Extracts the adjustment value.
        int index = adjustment[1];  // Extracts the index of the sensor to be adjusted.

        // Updates the value in humidity1[index] with the adjustment.
        humidity1[index] += value;

        // Calculates the sum of even values in the humidity array after the update using reduce.
        auto sum = reduce(
            exec_seq{},       // Specifies sequential execution (ensures evaluation order).
            humidity1.begin(),        // Start of the humidity1 vector range.
            humidity1.end(),          // End of the humidity1 vector range.
            0LL,                      // Initial sum value (0), with type long long to avoid overflow.
            [](auto acc, auto val) {  // Using auto for lambda parameters
                return acc + (val % 2 == 0 ? val : 0);  // Adds to the sum if the value is even.
            }
        );

        // Adds the current sum of even values to the result vector.
        result1.push_back(sum);
    }

    // Prints the results for example 1.
    cout << "Example 1:\n";
    printResult(humidity1, adjustments1, result1);

    // Example 2
    vi humidity2 = { 40 };  // Initial humidity vector for the second example.
    vvi adjustments2 = { {12,0} };  // Adjustments vector for the second example.

    // Create a vector to store the results.
    vll result2;
    result2.reserve(adjustments2.size());

    // Iterates over each provided adjustment.
    for (const auto& adjustment : adjustments2) {
        int value = adjustment[0];  // Extracts the adjustment value.
        int index = adjustment[1];  // Extracts the index of the sensor to be adjusted.

        // Updates the value in humidity2[index] with the adjustment.
        humidity2[index] += value;

        // Calculates the sum of even values in the humidity array after the update using reduce.
        auto sum = reduce(
            exec_seq{},       // Specifies sequential execution (ensures evaluation order).
            humidity2.begin(),        // Start of the humidity2 vector range.
            humidity2.end(),          // End of the humidity2 vector range.
            0LL,                      // Initial sum value (0), with type long long to avoid overflow.
            [](auto acc, auto val) {  // Using auto for lambda parameters
                return acc + (val % 2 == 0 ? val : 0);  // Adds to the sum if the value is even.
            }
        );

        // Adds the current sum of even values to the result vector.
        result2.push_back(sum);
    }

    // Prints the results for example 2.
    cout << "Example 2:\n";
    printResult(humidity2, adjustments2, result2);

    return 0;  // Indicates that the program finished successfully.
}
