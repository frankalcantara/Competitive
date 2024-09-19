#include <vector>
#include <iostream>
using namespace std;
using vi = vector<long long>;

// Function to compute the sum of even numbers after each adjustment
vi sumEvenAfterAdjustments(vi& humidity, const vector<vi>& adjustments) {
    long long sumEven = 0;
    vi result;

    // Calculate the initial sum of even numbers in the humidity array
    for (auto level : humidity) {
        if (level % 2 == 0) {
            sumEven += level;
        }
    }

    // Process each adjustment
    for (const auto& adjustment : adjustments) {
        long long val = adjustment[0];  // The adjustment value to add
        int index = adjustment[1];      // The index of the sensor to adjust
        long long oldValue = humidity[index];  // Store the old humidity value
        long long newValue = oldValue + val;   // Compute the new humidity value

        // Apply the adjustment to the humidity array
        humidity[index] = newValue;

        // --- Incremental sum update algorithm starts here ---
        // Update sumEven based on the old and new values

        // If the old value was even, subtract it from sumEven
        if (oldValue % 2 == 0) {
            sumEven -= oldValue;  // Remove the old even value from the sum
        }
        // If the new value is even, add it to sumEven
        if (newValue % 2 == 0) {
            sumEven += newValue;  // Add the new even value to the sum
        }
        // --- Incremental sum update algorithm ends here ---

        // Store the current sum after the adjustment
        result.push_back(sumEven);
    }
    return result;
}

int main() {
    // Example 1
    vi humidity1 = { 45, 52, 33, 64 };
    vector<vi> adjustments1 = { {5, 0}, {-20, 1}, {-14, 0}, {18, 3} };
    vi result1 = sumEvenAfterAdjustments(humidity1, adjustments1);
    cout << "Example 1: ";
    for (const auto& sum : result1) cout << sum << " ";
    cout << endl;

    // Example 2
    vi humidity2 = { 40 };
    vector<vi> adjustments2 = { {12, 0} };
    vi result2 = sumEvenAfterAdjustments(humidity2, adjustments2);
    cout << "Example 2: ";
    for (const auto& sum : result2) cout << sum << " ";
    cout << endl;

    // Example 3
    vi humidity3 = { 30, 41, 55, 68, 72 };
    vector<vi> adjustments3 = { {10, 0}, {-15, 2}, {22, 1}, {-8, 4}, {5, 3} };
    vi result3 = sumEvenAfterAdjustments(humidity3, adjustments3);
    cout << "Example 3: ";
    for (const auto& sum : result3) cout << sum << " ";
    cout << endl;

    return 0;
}
