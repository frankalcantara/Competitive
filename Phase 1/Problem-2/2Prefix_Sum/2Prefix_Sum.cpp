#include <iostream>
#include <vector>

using namespace std;

// Function to find the index of the Magic Plate
int find_magic_plate(const vector<int>& plates) {
    int n = plates.size();

    // If there is only one plate, it is automatically the Magic Plate
    if (n == 1) return 0;

    // Create a prefix sum array to store the cumulative sum up to each plate
    vector<int> prefix_sum(n + 1, 0);

    // Build the prefix sum array where each element contains the sum of elements up to that index
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + plates[i - 1];
    }

    // Calculate total sum (optional step, just for clarity)
    int total_sum = prefix_sum[n];

    // Check for each plate if the left sum equals the right sum
    for (int i = 1; i <= n; ++i) {
        // Left sum is the sum of elements before the current plate
        int left_sum = prefix_sum[i - 1];

        // Right sum is the total sum minus the current prefix sum
        int right_sum = total_sum - prefix_sum[i];

        // If the left and right sums are equal, return the current index (0-based)
        if (left_sum == right_sum) {
            return i - 1;
        }
    }

    // If no Magic Plate is found, return -1
    return -1;
}

int main() {
    // Example 1: plates = [3, 1, 5, 2, 2]
    vector<int> plates1 = { 3, 1, 5, 2, 2 };
    int result1 = find_magic_plate(plates1);
    cout << "Magic Plate index for plates1: " << result1 << endl;

    // Example 2: plates = [1, 2, 3]
    vector<int> plates2 = { 1, 2, 3 };
    int result2 = find_magic_plate(plates2);
    cout << "Magic Plate index for plates2: " << result2 << endl;

    // Example 3: plates = [2, 1, -1]
    vector<int> plates3 = { 2, 1, -1 };
    int result3 = find_magic_plate(plates3);
    cout << "Magic Plate index for plates3: " << result3 << endl;

    return 0;
}
