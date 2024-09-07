#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
Complexity Analysis:

1. findMagicPlate function:
   - Time: O(n), where n is the number of plates.
     * First loop to calculate totalSum: O(n)
     * Second loop to find the Magic Plate: O(n)
   - Space: O(1), as it uses only a few extra variables, regardless of input size.

2. main function:
   - Time: O(T * n), where T is the number of test cases and n is the average size of each array.
     * Reading the number of cases: O(1)
     * For each test case:
       - Reading and processing the line: O(n)
       - Calling findMagicPlate: O(n)
   - Space: O(n), where n is the size of the largest input array.
     * The 'plates' vector stores one array at a time.

Overall Complexity:
- Time: O(T * n)
- Space: O(n)

Observations:
1. The solution is time-efficient, processing each array in linear time.
2. Memory usage is optimized, processing one array at a time instead of storing all arrays simultaneously.
3. File I/O may add overhead, but this is constant and doesn't affect the asymptotic complexity.
*/

// Function to find the "Magic Plate" index using an efficient single-pass approach.
int findMagicPlate(const vector<int>& plates) {
    int n = plates.size(); // Get the size of the array
    int totalSum = 0;
    for (int plate : plates) {
        totalSum += plate;
    }

    int leftSum = 0;
    for (int i = 0; i < n; ++i) {
        if (leftSum == totalSum - leftSum - plates[i]) {
            return i; // Return the index of the Magic Plate
        }
        leftSum += plates[i];
    }
    return -1; // If no Magic Plate is found, return -1
}

int main(int argc, char* argv[]) {
    // Disable synchronization with C I/O for faster input/output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Check if the user provided a file name as an argument
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1; // Return 1 to indicate an error
    }

    // Open the input file
    ifstream file(argv[1]);

    // Check if the file was opened successfully
    if (!file) {
        cerr << "Error: could not open file " << argv[1] << "\n";
        return 1;
    }

    // Read the number of arrays from the first line
    int numArrays;
    file >> numArrays;
    file.ignore(); // Ignore the newline character after numArrays

    // Process each array one by one
    for (int arrayIndex = 0; arrayIndex < numArrays; ++arrayIndex) {
        // Vector to store the weights of the plates
        vector<int> plates;
        string line;
        getline(file, line);

        // Use stringstream to parse the line
        istringstream iss(line);
        int num;
        while (iss >> num) {
            plates.push_back(num);
        }

        // Call the function to find the Magic Plate index
        int magicPlateIndex = findMagicPlate(plates);

        // Output the result with no extra text, one result per line
        cout << magicPlateIndex << "\n";
    }

    // Close the file after processing all data
    file.close();
    return 0; // Return 0 to indicate the program finished successfully
}