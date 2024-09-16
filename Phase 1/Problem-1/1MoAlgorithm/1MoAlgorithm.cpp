#include <iostream>
#include <vector>

using namespace std;

// Function to handle Mo's Algorithm for the humidity adjustments
vector<int> mo_algorithm(vector<int>& humidity, vector<pair<int, int>>& adjustments) {
    int n = humidity.size();  // Number of sensors
    int q = adjustments.size();  // Number of adjustments

    vector<int> result(q);  // To store the result for each adjustment
    int even_sum = 0;  // To keep track of the sum of even numbers

    // Calculate initial even sum
    for (int i = 0; i < n; i++) {
        if (humidity[i] % 2 == 0) {
            even_sum += humidity[i];
        }
    }

    // Process each adjustment
    for (int i = 0; i < q; i++) {
        int adj_value = adjustments[i].first;  // Value to add
        int sensor_index = adjustments[i].second;  // Sensor index

        // If the current value is even, remove it from the even sum
        if (humidity[sensor_index] % 2 == 0) {
            even_sum -= humidity[sensor_index];
        }

        // Apply the adjustment to the sensor
        humidity[sensor_index] += adj_value;

        // If the new value is even, add it to the even sum
        if (humidity[sensor_index] % 2 == 0) {
            even_sum += humidity[sensor_index];
        }

        // Store the result for this adjustment
        result[i] = even_sum;
    }

    return result;
}

void print_example(const vector<int>& humidity, const vector<pair<int, int>>& adjustments, const vector<int>& result, int example_num) {
    // Print the formatted example output
    cout << "Example " << example_num << ":" << endl;
    cout << "Input: humidity = [";
    for (size_t i = 0; i < humidity.size(); ++i) {
        cout << humidity[i];
        if (i < humidity.size() - 1) cout << ", ";
    }
    cout << "], adjustments = [";
    for (size_t i = 0; i < adjustments.size(); ++i) {
        cout << "[" << adjustments[i].first << "," << adjustments[i].second << "]";
        if (i < adjustments.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Output: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl << endl;
}

int main() {
    // Example 1
    vector<int> humidity1 = { 45, 52, 33, 64 };
    vector<pair<int, int>> adjustments1 = { {5, 0}, {-20, 1}, {-14, 0}, {18, 3} };
    vector<int> result1 = mo_algorithm(humidity1, adjustments1);  // Process the adjustments
    print_example(humidity1, adjustments1, result1, 1);

    // Example 2
    vector<int> humidity2 = { 40 };
    vector<pair<int, int>> adjustments2 = { {12, 0} };
    vector<int> result2 = mo_algorithm(humidity2, adjustments2);  // Process the adjustments
    print_example(humidity2, adjustments2, result2, 2);

    // Example 3
    vector<int> humidity3 = { 30, 41, 55, 68, 72 };
    vector<pair<int, int>> adjustments3 = { {10, 0}, {-15, 2}, {22, 1}, {-8, 4}, {5, 3} };
    vector<int> result3 = mo_algorithm(humidity3, adjustments3);  // Process the adjustments
    print_example(humidity3, adjustments3, result3, 3);

    return 0;
}
