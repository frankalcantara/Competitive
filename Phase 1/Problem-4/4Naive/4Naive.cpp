#include <iostream>   // Includes the library for standard input/output operations
#include <vector>     // Includes the library for using dynamic arrays (vectors)
#include <string>     // Includes the library for handling strings

using namespace std;  // Allows using standard library objects without the "std::" prefix

int main(int argc, char* argv[]) {
    // The main function takes two arguments:
    // 'argc' is the number of command-line arguments (including the program name)
    // 'argv' is an array of strings containing the arguments passed via the command line

    // The function 'stoi' (string to integer) converts a string (const char*) to an integer.
    // Here we are converting the command-line arguments to integers.
    // 'argv[1]' contains the value of 'n' (size of the array), and 'argv[2]' contains the value of 'T' (target).
    int n = stoi(argv[1]);
    int T = stoi(argv[2]);

    // We create a vector of integers to store the sales data.
    // The size of the 'sales' vector is defined by 'n'.
    vector<int> sales(n);

    // This loop fills the 'sales' vector with the values provided as arguments.
    // Each 'sales' value is extracted from 'argv[i+3]', as the first 3 elements of 'argv' are the program name, 'n', and 'T'.
    for (int i = 0; i < n; ++i) {
        sales[i] = stoi(argv[i + 3]);  // Converts the command-line argument from string to integer and stores it in the vector
    }

    // Initialize the variable 'count', which will be used to count how many subarrays have a sum divisible by T.
    int count = 0;

    // This outer loop iterates over all possible starting points of subarrays.
    for (int start = 0; start < n; ++start) {
        int subarray_sum = 0;  // Initialize the sum of the subarray

        // This inner loop expands the subarray starting at the 'start' index up to the 'end' index.
        for (int end = start; end < n; ++end) {
            subarray_sum += sales[end];  // Accumulate the sum of the subarray by adding the value of 'sales[end]'

            // If the sum of the subarray is divisible by T (subarray_sum % T == 0), increment the counter.
            if (subarray_sum % T == 0) {
                count++;  // Count this subarray as valid
            }
        }
    }

    // Display the final result: the total number of subarrays whose sum is divisible by T.
    cout << count << endl;

    // Return 0, indicating that the program was executed successfully.
    return 0;
}
