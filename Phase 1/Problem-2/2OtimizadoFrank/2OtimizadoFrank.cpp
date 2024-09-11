#include <iostream>
#include <vector>
#include <unordered_map>

// Function to find the "Magic Plate" where the sum of plates to the left
// equals the sum of plates to the right
void encontrar_prato_magico(const std::vector<int>& pratos) {
    int n = pratos.size();  // Store the size of the array of plates

    // Dictionaries (unordered_map) to store cumulative sums from the left and right
    std::unordered_map<int, int> soma_esquerda;  // Stores cumulative sum from the left up to index 'i'
    std::unordered_map<int, int> soma_direita;   // Stores cumulative sum from the right up to index 'n-1-i'

    // Variables to accumulate sums from the left and right during the loop
    int soma_e = 0;  // Left sum
    int soma_d = 0;  // Right sum

    // Main loop: iterates through the array of plates once
    for (int i = 0; i < n; ++i) {
        // Update the left sum
        soma_e += pratos[i];
        soma_esquerda[i] = soma_e;  // Store the left sum in the dictionary for index 'i'

        // Check if there is already a matching entry in soma_direita
        // If there's an entry in soma_direita with the same sum and index, a "Magic Plate" is found
        if (soma_direita.contains(i) && soma_direita[i] == soma_e) {
            std::cout << "Magic Plate found at index: " << i << std::endl;
            return;  // Exit the function once a Magic Plate is found
        }

        // Update the right sum
        soma_d += pratos[n - 1 - i];
        soma_direita[n - 1 - i] = soma_d;  // Store the right sum in the dictionary for index 'n-1-i'

        // Check if there's already a matching entry in soma_esquerda
        // If there's an entry in soma_esquerda with the same sum and index, a "Magic Plate" is found
        if (soma_esquerda.contains(n - 1 - i) && soma_esquerda[n - 1 - i] == soma_d) {
            std::cout << "Magic Plate found at index: " << n - 1 - i << std::endl;
            return;  // Exit the function once a Magic Plate is found
        }
    }

    // If no Magic Plate is found after the loop completes
    std::cout << "-1" << std::endl;
}

int main() {
    // Test Example 1: pratos = {3, 1, 5, 2, 2}
    std::vector<int> pratos1 = { 3, 1, 5, 2, 2 };
    std::cout << "Test with pratos1 = {3, 1, 5, 2, 2}:" << std::endl;
    encontrar_prato_magico(pratos1);

    // Test Example 2: pratos = {1, 2, 3}
    std::vector<int> pratos2 = { 1, 2, 3 };
    std::cout << "Test with pratos2 = {1, 2, 3}:" << std::endl;
    encontrar_prato_magico(pratos2);

    // Test Example 3: pratos = {2, 1, -1}
    std::vector<int> pratos3 = { 2, 1, -1 };
    std::cout << "Test with pratos3 = {2, 1, -1}:" << std::endl;
    encontrar_prato_magico(pratos3);

    return 0;  // End of program
}
