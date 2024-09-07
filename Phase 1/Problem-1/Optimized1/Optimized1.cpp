// translated by chatgpt 2024-09-07
#include <iostream>
#include <vector>

using namespace std;

// Function that adjusts humidity levels and calculates the sum of even values after each adjustment.
vector<long long> adjustHumidity(vector<int>& humidity, const vector<vector<int>>& adjustments) {
    // Initializes the sum of even numbers to zero.
    long long sum = 0;

    // Calculates the initial sum of even values in the humidity array.
    for (int h : humidity) {
        if (h % 2 == 0) {  // Checks if the value is even.
            sum += h;  // Adds to the sum if it is even.
        }
    }

    // Creates a vector to store the results, reserving enough space to avoid unnecessary reallocations.
    vector<long long> result;
    result.reserve(adjustments.size());

    // Iterates over each provided adjustment.
    for (const auto& adjustment : adjustments) {
        int value = adjustment[0];  // Extracts the adjustment value.
        int index = adjustment[1];  // Extracts the index of the sensor to be adjusted.

        // Checks if the current value at humidity[index] is even.
        if (humidity[index] % 2 == 0) {
            sum -= humidity[index];  // If it is even, subtracts it from the sum of evens.
        }

        // Updates the value at humidity[index] with the adjustment.
        humidity[index] += value;

        // Checks if the new value at humidity[index] is even after the update.
        if (humidity[index] % 2 == 0) {
            sum += humidity[index];  // If it is even, adds it to the sum of evens.
        }

        // Adds the current sum of even values to the results vector.
        result.push_back(sum);
    }

    // Returns the vector containing the sum of evens after each adjustment.
    return result;
}

// Helper function to print the results in a formatted way.
void printResult(const vector<int>& humidity, const vector<vector<int>>& adjustments, const vector<long long>& result) {
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
