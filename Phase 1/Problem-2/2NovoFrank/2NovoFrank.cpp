#include <iostream>
#include <vector>
#include <unordered_map>

void encontrar_prato_magico(const std::vector<int>& pratos) {
    int n = pratos.size();
    std::unordered_map<int, bool> somas;  // Dicion�rio para armazenar as somas
    int soma_esquerda = 0;
    int soma_direita = 0;

    // Itera��o principal: varre o array simultaneamente de ambos os lados
    for (int i = 0; i < n; ++i) {
        // Atualiza a soma � esquerda e verifica se j� est� no dicion�rio
        soma_esquerda += pratos[i];
        if (somas.contains(soma_esquerda) && i != n - 1 - i) {
            std::cout << "Magic Plate found at index: " << i << std::endl;
            return;
        }
        somas[soma_esquerda] = true;  // Armazena a soma � esquerda

        // Atualiza a soma � direita e verifica se j� est� no dicion�rio
        soma_direita += pratos[n - 1 - i];
        if (somas.contains(soma_direita) && n - 1 - i != i) {
            std::cout << "Magic Plate found at index: " << n - 1 - i << std::endl;
            return;
        }
        somas[soma_direita] = true;  // Armazena a soma � direita
    }

    // Se o loop terminar sem encontrar o "Prato M�gico"
    std::cout << "-1" << std::endl;
}

int main() {
    std::vector<int> pratos1 = { 3, 1, 5, 2, 2 };
    std::cout << "Test with pratos1 = {3, 1, 5, 2, 2}:" << std::endl;
    encontrar_prato_magico(pratos1);

    std::vector<int> pratos2 = { 1, 2, 3 };
    std::cout << "Test with pratos2 = {1, 2, 3}:" << std::endl;
    encontrar_prato_magico(pratos2);

    std::vector<int> pratos3 = { 2, 1, -1 };
    std::cout << "Test with pratos3 = {2, 1, -1}:" << std::endl;
    encontrar_prato_magico(pratos3);

    return 0;
}
