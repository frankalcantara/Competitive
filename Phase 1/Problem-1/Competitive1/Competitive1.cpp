#include <iostream>
#include <vector>
#include <numeric>
#include <execution>  // Necessário para políticas de execução em reduce

using namespace std;

// Função auxiliar para imprimir os resultados de forma formatada.
void printResult(const vector<int>& humidity, const vector<vector<int>>& adjustments, const vector<long long>& result) {
    // Imprime a umidade inicial e os ajustes.
    cout << "Input: humidity = [";
    for (size_t i = 0; i < humidity.size(); ++i) {
        cout << humidity[i] << (i < humidity.size() - 1 ? ", " : "");
    }
    cout << "], adjustments = [";
    for (size_t i = 0; i < adjustments.size(); ++i) {
        cout << "[" << adjustments[i][0] << "," << adjustments[i][1] << "]" << (i < adjustments.size() - 1 ? ", " : "");
    }
    cout << "]\n";

    // Imprime o resultado após cada ajuste.
    cout << "Output: ";
    for (long long res : result) {
        cout << res << " ";
    }
    cout << "\n\n";
}

int main() {
    // Exemplo 1
    vector<int> humidity1 = { 45, 52, 33, 64 };  // Vetor de umidade inicial.
    vector<vector<int>> adjustments1 = { {5,0}, {-20,1}, {-14,0}, {18,3} };  // Vetor de ajustes.

    // Cria um vetor para armazenar os resultados, reservando espaço suficiente para evitar realocações desnecessárias.
    vector<long long> result1;
    result1.reserve(adjustments1.size());

    // Itera sobre cada ajuste fornecido.
    for (const auto& adjustment : adjustments1) {
        int value = adjustment[0];  // Extrai o valor de ajuste.
        int index = adjustment[1];  // Extrai o índice do sensor que será ajustado.

        // Atualiza o valor em humidity1[index] com o ajuste.
        humidity1[index] += value;

        // Calcula a soma dos valores pares no array de umidade após a atualização usando reduce.
        long long sum = reduce(
            execution::seq,      // Especifica execução sequencial (garante a ordem de avaliação).
            humidity1.begin(),        // Início do intervalo do vetor humidity1.
            humidity1.end(),          // Fim do intervalo do vetor humidity1.
            0LL,                      // Valor inicial da soma (0), com tipo long long para evitar estouro.
            [](long long acc, int val) {  // Função lambda para definir a operação de acumulação.
                return acc + (val % 2 == 0 ? val : 0);  // Adiciona à soma se o valor for par.
            }
        );

        // Adiciona a soma atual dos valores pares ao vetor de resultados.
        result1.push_back(sum);
    }

    // Imprime os resultados para o exemplo 1.
    cout << "Exemplo 1:\n";
    printResult(humidity1, adjustments1, result1);

    // Exemplo 2
    vector<int> humidity2 = { 40 };  // Vetor de umidade inicial para o segundo exemplo.
    vector<vector<int>> adjustments2 = { {12,0} };  // Vetor de ajustes para o segundo exemplo.

    // Cria um vetor para armazenar os resultados.
    vector<long long> result2;
    result2.reserve(adjustments2.size());

    // Itera sobre cada ajuste fornecido.
    for (const auto& adjustment : adjustments2) {
        int value = adjustment[0];  // Extrai o valor de ajuste.
        int index = adjustment[1];  // Extrai o índice do sensor que será ajustado.

        // Atualiza o valor em humidity2[index] com o ajuste.
        humidity2[index] += value;

        // Calcula a soma dos valores pares no array de umidade após a atualização usando reduce.
        long long sum = reduce(
            execution::seq,      // Especifica execução sequencial (garante a ordem de avaliação).
            humidity2.begin(),        // Início do intervalo do vetor humidity2.
            humidity2.end(),          // Fim do intervalo do vetor humidity2.
            0LL,                      // Valor inicial da soma (0), com tipo long long para evitar estouro.
            [](long long acc, int val) {  // Função lambda para definir a operação de acumulação.
                return acc + (val % 2 == 0 ? val : 0);  // Adiciona à soma se o valor for par.
            }
        );

        // Adiciona a soma atual dos valores pares ao vetor de resultados.
        result2.push_back(sum);
    }

    // Imprime os resultados para o exemplo 2.
    cout << "Exemplo 2:\n";
    printResult(humidity2, adjustments2, result2);

    return 0;  // Indica que o programa terminou com sucesso.
}
