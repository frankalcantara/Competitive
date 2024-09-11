#include <iostream>      // Standard library for input/output.
#include <vector>        // Standard library for using dynamic arrays (vectors).
#include <numeric>       // Contains numeric algorithms like accumulate (not used here but available).
#include <fstream>       // For reading from and writing to files.
#include <sstream>       // For stream manipulation.
#include <filesystem>    // For interacting with the file system.
#include <syncstream>    // For thread-safe output using synchronized streams.

using namespace std;  // Use the standard namespace to avoid typing "std::" before standard types.
namespace fs = filesystem;  // Alias for the filesystem namespace.

namespace config {
    // Enum class defining different input methods: Hardcoded, Stdin (standard input), and File.
    enum class InputMethod { Hardcoded, Stdin, File };

    // This inline configuration constant defines the current input method.
    // By default, it is set to Hardcoded input.
    inline constexpr InputMethod input_method = InputMethod::Hardcoded;
}

// Type aliases to reduce verbosity when using vectors.
using vi = vector<int>;               // Alias for vector of integers.
using vvi = vector<vector<int>>;      // Alias for 2D vector of integers.
using vll = vector<long long>;        // Alias for vector of long long integers (for larger sums).

// Class that implements a Binary Indexed Tree (BIT) for efficient range queries and updates.
class BIT {
    vi tree;  // Vector that holds the tree structure.
    int n;    // Size of the tree.

public:
    // Constructor initializes the tree with size+1, because BITs are typically 1-indexed.
    BIT(int size) : tree(size + 1), n(size) {}

    // Function to update the value at index `i` by adding `delta`.
    void update(int i, int delta) {
        // Increment index to convert it to 1-based index.
        for (++i; i <= n; i += i & -i) tree[i] += delta;  // Propagate delta through the BIT.
    }

    // Function to query the sum of values from index 0 to index `i`.
    long long query(int i) const {
        long long sum = 0;
        // Convert index to 1-based and sum the relevant entries in the tree.
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;  // Return the accumulated sum.
    }
};

// Function to adjust humidity levels based on adjustments and return the sum of even values after each adjustment.
vll adjustHumidity(vi& humidity, const vvi& adjustments) {
    int n = humidity.size();  // Get the size of the humidity vector.
    BIT bit(n);               // Create a Binary Indexed Tree (BIT) for the humidity array.
    vll result;               // Vector to store the results (sum of even values).
    result.reserve(adjustments.size());  // Pre-allocate space to avoid reallocation.

    // Lambda function to handle updating the BIT when humidity values change.
    auto updateBit = [&](int i, int old_val, int new_val) {
        // If the old value was even, remove it from the BIT.
        if (!(old_val & 1)) bit.update(i, -old_val);
        // If the new value is even, add it to the BIT.
        if (!(new_val & 1)) bit.update(i, new_val);
        };

    // Initialize the BIT with the even values from the humidity vector.
    for (int i = 0; i < n; ++i) {
        if (!(humidity[i] & 1)) bit.update(i, humidity[i]);  // Add even values to the BIT.
    }

    // Process each adjustment.
    for (const auto& adj : adjustments) {
        int i = adj[1], old_val = humidity[i], new_val = old_val + adj[0];  // Get index and compute new value.
        updateBit(i, old_val, new_val);  // Update the BIT based on the value change.
        humidity[i] = new_val;  // Apply the adjustment to the humidity array.
        result.push_back(bit.query(n - 1));  // Query the BIT to get the sum of even values and store it.
    }

    return result;  // Return the vector containing results after each adjustment.
}

// Function to print the input humidity values, adjustments, and results to an output stream.
void printResult(osyncstream& out, const vi& humidity, const vvi& adjustments, const vll& result) {
    out << "Input: humidity = [" << humidity[0];
    for (int i = 1; i < humidity.size(); ++i) out << ", " << humidity[i];  // Print all humidity values.
    out << "], adjustments = [";
    for (const auto& adj : adjustments)
        out << "[" << adj[0] << "," << adj[1] << "]" << (&adj != &adjustments.back() ? ", " : "");  // Print all adjustments.
    out << "]\nOutput: ";
    for (auto res : result) out << res << " ";  // Print all results (sum of even values).
    out << "\n\n";
}

// Function to read input from a stream (either stdin or file).
pair<vi, vvi> readInput(istream& in) {
    vi humidity;  // Vector to store humidity levels.
    vvi adjustments;  // 2D vector to store adjustments.
    int n, m;  // n is the number of humidity sensors, m is the number of adjustments.
    in >> n;  // Read the number of humidity levels.
    humidity.resize(n);  // Resize the humidity vector.
    for (int& h : humidity) in >> h;  // Read each humidity value.
    in >> m;  // Read the number of adjustments.
    adjustments.resize(m, vi(2));  // Resize the adjustments vector to hold m pairs of integers.
    for (auto& adj : adjustments) in >> adj[0] >> adj[1];  // Read each adjustment (value and index).
    return { humidity, adjustments };  // Return the humidity vector and adjustments vector.
}

// Function to process multiple input cases from the stream.
void processInput(istream& in, osyncstream& out) {
    int t;  // Number of test cases.
    in >> t;  // Read the number of test cases.
    for (int i = 1; i <= t; ++i) {
        out << "Example " << i << ":\n";  // Print the test case number.
        auto [humidity, adjustments] = readInput(in);  // Read input for this test case.
        auto result = adjustHumidity(humidity, adjustments);  // Compute the results.
        printResult(out, humidity, adjustments, result);  // Print the results.
    }
}

int main() {
    osyncstream syncout(cout);  // Create a synchronized output stream to avoid race conditions.

    // Handle hardcoded input case.
    if constexpr (config::input_method == config::InputMethod::Hardcoded) {
        // Predefined test cases (hardcoded).
        vector<pair<vi, vvi>> tests = {
            {{45, 52, 33, 64}, {{5,0}, {-20,1}, {-14,0}, {18,3}}},
            {{40}, {{12,0}}},
            {{30, 41, 55, 68, 72}, {{10,0}, {-15,2}, {22,1}, {-8,4}, {5,3}}}
        };

        // Iterate through each hardcoded test case.
        for (int i = 0; i < tests.size(); ++i) {
            syncout << "Example " << i + 1 << ":\n";  // Print the example number.
            auto& [humidity, adjustments] = tests[i];  // Get the humidity and adjustments for this test.
            auto result = adjustHumidity(humidity, adjustments);  // Adjust humidity and compute results.
            printResult(syncout, humidity, adjustments, result);  // Print the results.
        }
    }
    // Handle input from stdin.
    else if constexpr (config::input_method == config::InputMethod::Stdin) {
        processInput(cin, syncout);  // Process input from stdin.
    }
    // Handle input from a file.
    else if constexpr (config::input_method == config::InputMethod::File) {
        fs::path inputPath = "input.txt";  // Define the path to the input file.
        if (fs::exists(inputPath)) {  // Check if the file exists.
            ifstream inputFile(inputPath);  // Open the input file.
            processInput(inputFile, syncout);  // Process the input from the file.
        }
        else {
            syncout << "Input file not found: " << inputPath << endl;  // Error message if the file doesn't exist.
        }
    }
    else {
        syncout << "Invalid input method defined" << endl;  // Error message for an invalid input method.
    }

    return 0;  // Return 0 to indicate successful program termination.
}
