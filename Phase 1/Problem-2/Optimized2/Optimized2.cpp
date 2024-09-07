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

// Função para encontrar o índice do "Magic Plate" usando uma abordagem eficiente com passagem única.
int findMagicPlate(const vector<int>& plates) {
    int n = plates.size(); // Obtém o tamanho do array
    int totalSum = 0;
    for (int plate : plates) {
        totalSum += plate;
    }

    int leftSum = 0;
    for (int i = 0; i < n; ++i) {
        if (leftSum == totalSum - leftSum - plates[i]) {
            return i; // Retorna o índice do Magic Plate
        }
        leftSum += plates[i];
    }
    return -1; // Se nenhum Magic Plate for encontrado, retorna -1
}

int main(int argc, char* argv[]) {
    // Desabilita a sincronização com a I/O do C para entrada/saída mais rápida
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Verifica se o usuário forneceu um nome de arquivo como argumento
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1; // Retorna 1 para indicar um erro
    }

    // Abre o arquivo de entrada
    ifstream file(argv[1]);

    // Verifica se o arquivo foi aberto com sucesso
    if (!file) {
        cerr << "Error: could not open file " << argv[1] << "\n";
        return 1;
    }

    // Lê o número de arrays da primeira linha
    int numArrays;
    file >> numArrays;
    file.ignore(); // Ignora o caractere de nova linha após numArrays

    // Processa cada array um por um
    for (int arrayIndex = 0; arrayIndex < numArrays; ++arrayIndex) {
        // Vetor para armazenar os pesos dos pratos
        vector<int> plates;
        string line;
        getline(file, line); // Lê a linha que contém os números do array

        // Usa stringstream para analisar a linha e extrair os números
        istringstream iss(line);
        int num;
        while (iss >> num) {
            plates.push_back(num); // Adiciona os números ao vetor
        }

        // Chama a função para encontrar o índice do Magic Plate
        int magicPlateIndex = findMagicPlate(plates);

        // Exibe o resultado com um valor por linha
        cout << magicPlateIndex << "\n";
    }

    // Fecha o arquivo após processar todos os dados
    file.close();
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
