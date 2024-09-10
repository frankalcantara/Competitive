// translated to English by chatgpt in 2024-09-07
#include <iostream>   // Library for standard input and output operations
#include <fstream>    // Library for file reading and writing operations
#include <vector>     // Library to use the vector data structure
#include <string>     // Library for string manipulation
#include <algorithm>  // Library for standard algorithms, like sort
#include <random>     // Library for random number generation
#include <chrono>     // Library for time manipulation and high-resolution clock

// Using `using` to reduce the typing of long types
using namespace std;

using vi = vector<int>;              // Alias for `vector<int>`
using vvi = vector<vector<int>>;     // Alias for `vector<vector<int>>`
using uint = unsigned int;           // Alias for `unsigned int`
using mt19937_gen = mt19937;         // Alias for `mt19937`

// Function to print the vector
// The print_vector function receives an integer vector as an argument, but instead of passing the vector directly,
// it uses a constant reference (const vector<int>& vec). This has several important implications:
//
// 1. **const**: Ensures that the vector will not be modified inside the function. This is useful to protect the data and
//    ensure that the function is only for reading.
//
// 2. **vector<int>&**: The use of reference (&) avoids copying the entire vector when the function is called. 
//    Passing a vector by value (without reference) would result in a complete copy of the vector, which can be
//    inefficient, especially for large vectors.
//
// 3. **const vector<int>&**: Combining const with the reference allows the function to be efficient 
//    (no data copying) and safe (no modification of the original data).
//
// This pattern is common in C++ when passing large data structures to functions that do not need to modify the data.
void print_vector(const vi& vec) {
    // Iterates over each element of the vector using a for loop with index iteration
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";  // Accesses the element at index `i` and prints it
    }
    // Prints a new line after all elements have been printed
    cout << endl;
}

int main(int argc, char* argv[]) {
    // Disables synchronization between C and C++ I/O libraries to improve the performance of I/O operations.
    ios::sync_with_stdio(false);

    // Unlinks cin from cout to further improve input and output performance.
    cin.tie(nullptr);

    // Checks if the number of command-line arguments is equal to 2.
    // This is important because the program expects an argument specifying the file name to be read.
    if (argc != 2) {
        // If the number of arguments is different from 2, it prints an error message explaining the correct usage of the program.
        cerr << "Usage: " << argv[0] << " <file_name>\n";
        return 1;  // Returns 1 to indicate that the program terminated due to an error.
    }

    // Opens the file whose name was passed as a command-line argument.
    ifstream file(argv[1]);

    // Checks if the file was opened successfully.
    // Otherwise, it prints an error message and exits the program with error code 1.
    if (!file) {
        cerr << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    // Declares a string to store the first line of the file, which should contain the size of the vector.
    string line;
    getline(file, line);  // Reads the first line of the file and stores it in the 'line' variable.

    // Converts the read string to an integer representing the size of the vector.
    int size = stoi(line);

    // Declares an integer vector called 'vec' and reserves space for 'size' elements.
    // Reserving space in advance avoids unnecessary reallocations during insertions, improving efficiency.
    vi vec;
    vec.reserve(size);

    // Declares a variable to temporarily store each number read from the file.
    int num;

    // Reads the rest of the file and stores each number in the 'vec' vector.
    // The loop ends when all numbers have been read.
    while (file >> num) {
        vec.push_back(num);  // Adds the number read to the end of the 'vec' vector.
    }

    // Closes the file since it is no longer needed after reading the data.
    file.close();

    // Prints the original vector read from the file for verification.
    cout << "Original vector: ";
    print_vector(vec);

    // Inserts the value 42 at position 5 of the vector if the vector size is greater than 5.
    // This demonstrates the use of the insert method to add elements at a specific position in the vector.
    if (vec.size() > 5) {
        vec.insert(vec.begin() + 5, 42);
        cout << "After insert at position 5: ";
        print_vector(vec);
    }

    // Removes the last element of the vector using the pop_back method if the vector is not empty.
    // This is useful to reduce the size of the vector by removing the most recent element.
    if (!vec.empty()) {
        vec.pop_back();
        cout << "After pop_back: ";
        print_vector(vec);
    }

    // Removes the element at position 3 of the vector if the vector size is greater than 3.
    // This demonstrates the use of the erase method to remove elements from a specific position.
    if (vec.size() > 3) {
        vec.erase(vec.begin() + 3);
        cout << "After erase at position 3: ";
        print_vector(vec);
    }

    // Creates a new vector 'vec2' with 5 elements, all initialized to the value 7.
    // This is useful for creating a vector with default values.
    vi vec2(5, 7);
    cout << "Vector with 5 elements (value 7): ";
    print_vector(vec2);

    // Resizes the 'vec2' vector to contain 10 elements.
    // The new elements will be initialized with the default value of the type, which for int is 0.
    vec2.resize(10);
    cout << "After resize to 10 elements: ";
    print_vector(vec2);

    // Generates a seed for the random number generator based on the current system time.
    uint seed = static_cast<uint>(chrono::high_resolution_clock::now().time_since_epoch().count());

    // Creates a Mersenne Twister generator for generating pseudo-random numbers.
    mt19937_gen generator(seed);

    // Defines a uniform integer distribution between 1 and 100.
    // Each number generated by the 'generator' will be within this range.
    uniform_int_distribution<int> distribution(1, 100);

    // Fills the 'vec2' vector with random values generated by the uniform distribution.
    for (size_t i = 0; i < vec2.size(); ++i) {
        vec2[i] = distribution(generator);
    }

    // Prints the 'vec2' vector after being filled with random values.
    cout << "After filling with random values: ";
    print_vector(vec2);

    // Sorts the 'vec2' vector in ascending order using the standard sort algorithm.
    sort(vec2.begin(), vec2.end());
    cout << "After sort: ";
    print_vector(vec2);

    // Example of a matrix using a vector of vectors (2D)
    // Here we create a 2x2 matrix, where each element is initialized to the value 1.
    int rows = 2, columns = 2;
    vvi matrix(rows, vi(columns));

    // Fills the matrix with the value 1 in all positions.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = 1;
        }
    }

    // Prints the matrix row by row.
    // The matrix is a vector of vectors, where each row of the matrix is a vector.
    cout << "Matrix:\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;  // Indicates that the program finished successfully.
}
