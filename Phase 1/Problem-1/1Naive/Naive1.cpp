// Translated by Chatgpt in 07/09/2024

#include <iostream>  // Includes the library for input and output.
#include <vector>    // Includes the library to use vectors.
#include <numeric>   // Includes the library that provides the accumulate function.

using namespace std;

// Function that adjusts the humidity levels and calculates the sum of even values after each adjustment.
vector<long long> adjustHumidity(vector<int>& humidity, const vector<vector<int>>& adjustments) {
    // Creates a vector to store the results, reserving enough space to avoid unnecessary reallocations.
    vector<long long> result;
    result.reserve(adjustments.size());

    // Iterates over each provided adjustment.
    for (const auto& adjustment : adjustments) {
        int value = adjustment[0];  // Extracts the adjustment value.
        int index = adjustment[1];  // Extracts the index of the sensor to be adjusted.

        // Updates the value at humidity[index] with the adjustment.
        humidity[index] += value;

        // Calculates the sum of even values in the humidity array after the update.
        long long sum = accumulate(humidity.begin(), humidity.end(), 0LL,
            [](long long acc, int val) {
                return acc + (val % 2 == 0 ? val : 0);  // Adds to the sum if the value is even.
            });

        // Adds the current sum of even values to the results vector.
        result.push_back(sum);
    }
    // Returns the vector containing the sum of even numbers after each adjustment.
    return result;
}

// Helper function to print the results in a formatted way.
void printResult(const vector<int>& humidity, const vector<vector<int>>& adjustments, const vector<long long>& result) {
    // Prints the initial humidity and adjustments.
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
    for (long long res : result) {
        cout << res << " ";
    }
    cout << "\n\n";
}

int main() {
    // Example 1
    vector<int> humidity1 = { 45, 52, 33, 64 };  // Initial humidity vector.
    vector<vector<int>> adjustments1 = { {5,0}, {-20,1}, {-14,0}, {18,3} };  // Adjustments vector.
    cout << "Example 1:\n";
    auto result1 = adjustHumidity(humidity1, adjustments1);  // Calculates the results.
    printResult(humidity1, adjustments1, result1);  // Prints the results.

    // Example 2
    vector<int> humidity2 = { 40 };  // Initial humidity vector.
    vector<vector<int>> adjustments2 = { {12,0} };  // Adjustments vector.
    cout << "Example 2:\n";
    auto result2 = adjustHumidity(humidity2, adjustments2);  // Calculates the results.
    printResult(humidity2, adjustments2, result2);  // Prints the results.

    return 0;  // Indicates that the program finished successfully.
}
