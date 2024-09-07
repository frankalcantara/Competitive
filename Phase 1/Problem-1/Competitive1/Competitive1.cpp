/*
   Complexity Analysis:
   - The time complexity is O(M + N), where M is the number of adjustments and N is the size of the humidity array.
     We only initialize the sum once (O(N)) and process each adjustment in O(1).
   - Space complexity is O(N), since we store the humidity and result arrays.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using vi = vector<int>;             // Abbreviation for vector of ints
using vvi = vector<vi>;             // Abbreviation for vector of vector<int>
using vll = vector<long long>;      // Abbreviation for vector of long long

// Helper function to print input and result
void printResult(const vi& humidity, const vvi& adjustments, const vll& result) {
    auto printVec = [](const auto& v, const string& sep = ", ") {
        for (size_t i = 0; i < v.size(); ++i) cout << v[i] << (i < v.size() - 1 ? sep : "");
        };

    cout << "Input: humidity = [";
    printVec(humidity);
    cout << "], adjustments = [";
    for (const auto& adj : adjustments) cout << "[" << adj[0] << "," << adj[1] << "]";
    cout << "]\nOutput: ";
    printVec(result, " ");
    cout << "\n\n";
}

int main() {
    vi humidity1 = { 45, 52, 33, 64 };      // Initial humidity vector
    vvi adjustments1 = { {5,0}, {-20,1}, {-14,0}, {18,3} }; // Adjustments

    vll result1;
    result1.reserve(adjustments1.size());

    long long evenSum1 = accumulate(humidity1.begin(), humidity1.end(), 0LL, [](long long acc, int val) {
        return acc + (val % 2 == 0 ? val : 0);
        });

    // Iterate over each adjustment without using structured bindings
    for (const auto& adjustment : adjustments1) {
        int val = adjustment[0];   // Extract the adjustment value
        int idx = adjustment[1];   // Extract the index

        if (humidity1[idx] % 2 == 0) evenSum1 -= humidity1[idx];
        humidity1[idx] += val;
        if (humidity1[idx] % 2 == 0) evenSum1 += humidity1[idx];
        result1.push_back(evenSum1);
    }

    cout << "Example 1:\n";
    printResult(humidity1, adjustments1, result1);

    vi humidity2 = { 40 };                            // Second example
    vvi adjustments2 = { {12,0} };
    vll result2;
    result2.reserve(adjustments2.size());

    long long evenSum2 = (humidity2[0] % 2 == 0 ? humidity2[0] : 0);

    for (const auto& adjustment : adjustments2) {
        int val = adjustment[0];   // Extract the adjustment value
        int idx = adjustment[1];   // Extract the index

        if (humidity2[idx] % 2 == 0) evenSum2 -= humidity2[idx];
        humidity2[idx] += val;
        if (humidity2[idx] % 2 == 0) evenSum2 += humidity2[idx];
        result2.push_back(evenSum2);
    }

    cout << "Example 2:\n";
    printResult(humidity2, adjustments2, result2);

    return 0;
}
