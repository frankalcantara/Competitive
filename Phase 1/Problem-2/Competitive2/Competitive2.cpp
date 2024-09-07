#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <ranges> // C++20 ranges library
using namespace std; // To avoid typing "std::"
// Shorthand for common types to minimize typing
using umii = unordered_map<int, int>;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false); cin.tie(nullptr); // Fast input/output
    if (argc != 2) { // Check for correct usage
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }
    ifstream file(argv[1]); // Open the input file
    if (!file) { // Error handling for file opening
        cerr << "Error: could not open file " << argv[1] << "\n";
        return 1;
    }
    int numArrays;
    file >> numArrays; // Read the number of arrays
    file.ignore(); // Ignore the newline after reading numArrays
    while (numArrays-- > 0) { // Process each array
        string line;
        getline(file, line); // Read the line containing the array
        istringstream iss(line);
        int totalSum = 0, runningSum = 0;
        umii prefixSumMap; // Map to store prefix sums
        prefixSumMap[0] = 0; // Initialize with 0 sum at index 0
        int i = 0; // Start index from 0
        // Using C++20's efficient range-based for loop to calculate both totalSum and runningSum
        for (int x : ranges::istream_view<int>(iss)) {
            totalSum += x; // Accumulate total sum
            runningSum += x; // Calculate running sum
            // Store the running sum in the map, associating it with the next index
            if (prefixSumMap.find(runningSum) == prefixSumMap.end()) {
                prefixSumMap[runningSum] = i + 1; // Store next index
            }
            i++;
        }
        // If total sum is not zero and odd, no solution is possible
        if (totalSum != 0 && totalSum % 2 != 0) {
            cout << -1 << "\n";
            continue;
        }
        int target = totalSum / 2;
        // Check if the target (half of total sum) exists in the map after the loop
        if (prefixSumMap.find(target) != prefixSumMap.end()) {
            cout << prefixSumMap[target] - 1 << "\n"; // Output the correct index of the "Magic Plate"
        }
        else {
            cout << -1 << "\n"; // If not found, print -1
        }
    }
    return 0; // Return 0 to indicate successful execution
}