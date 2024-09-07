#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
Complexity Analysis:

1. findMagicPlate function:
   - Time: O(n^2), where n is the number of plates.
     * Outer loop iterates n times
     * For each iteration, two inner loops each iterate up to n times
   - Space: O(1), as it uses only a few extra variables, regardless of input size.

2. main function:
   - Time: O(T * n^2), where T is the number of test cases and n is the average size of each array.
     * Reading the number of cases: O(1)
     * For each test case:
       - Reading and processing the line: O(n)
       - Calling findMagicPlate: O(n^2)
   - Space: O(n), where n is the size of the largest input array.
     * The 'plates' vector stores one array at a time.

Overall Complexity:
- Time: O(T * n^2)
- Space: O(n)

Observations:
1. This solution is less time-efficient than the O(n) solution, but it's more straightforward and easier to understand.
2. For small inputs, the performance difference might not be noticeable.
3. For larger inputs, this solution will be significantly slower than the O(n) version.
4. Memory usage remains the same as the previous version.
*/

// Function to find the "Magic Plate" index using a naive approach with two loops.
int findMagicPlate(const vector<int>& plates) {
    int n = plates.size(); // Get the size of the array

    // Loop through each plate to check if it's the Magic Plate
    for (int i = 0; i < n; ++i) {
        int leftSum = 0;  // Variable to store the sum of the left side
        int rightSum = 0; // Variable to store the sum of the right side

        // Calculate the sum of elements to the left of the current plate
        for (int j = 0; j < i; ++j) {
            leftSum += plates[j];
        }

        // Calculate the sum of elements to the right of the current plate
        for (int j = i + 1; j < n; ++j) {
            rightSum += plates[j];
        }

        // Check if the left sum is equal to the right sum
        if (leftSum == rightSum) {
            return i; // Return the index of the Magic Plate
        }
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