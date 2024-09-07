#include <iostream>   // Biblioteca para operações de entrada e saída padrão
#include <fstream>    // Biblioteca para operações de leitura e escrita em arquivos
#include <vector>     // Biblioteca para utilizar a estrutura de dados vector
#include <string>     // Biblioteca para manipulação de strings
#include <algorithm>  // Biblioteca para algoritmos padrão, como sort
#include <random>     // Biblioteca para geração de números aleatórios
#include <chrono>     // Biblioteca para manipulação de tempo e relógio de alta resolução

// Uso de `using` para reduzir a digitação de tipos longos
using namespace std;

using vi = vector<int>;              // Alias para `vector<int>`
using vvi = vector<vector<int>>;     // Alias para `vector<vector<int>>`
using uint = unsigned int;           // Alias para `unsigned int`
using mt19937_gen = mt19937;         // Alias para `mt19937`

// Função para imprimir o vetor
// A função print_vector recebe um vetor de inteiros como argumento, mas em vez de passar o vetor diretamente,
// utiliza-se uma referência constante (const vector<int>& vec). Isso tem várias implicações importantes:
//
// 1. **const**: Garante que o vetor não será modificado dentro da função. Isso é útil para proteger os dados e
//    garantir que a função serve apenas para leitura.
//
// 2. **vector<int>&**: O uso de referência (&) evita a cópia do vetor inteiro quando a função é chamada. 
//    Passar um vetor por valor (sem referência) resultaria em uma cópia completa do vetor, o que pode ser
//    ineficiente, especialmente para vetores grandes.
//
// 3. **const vector<int>&**: Combinar const com a referência permite que a função seja eficiente 
//    (sem cópia de dados) e segura (sem modificação dos dados originais).
//
// O uso deste padrão é comum em C++ quando se deseja passar grandes estruturas de dados para funções que não
// precisam modificar esses dados.
void print_vector(const vi& vec) {
    // Itera sobre cada elemento do vetor utilizando um laço for com iteração por índice
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";  // Acessa o elemento no índice `i` e o imprime
    }
    // Imprime uma nova linha após todos os elementos terem sido impressos
    cout << endl;
}

int main(int argc, char* argv[]) {
    // Desativa a sincronização entre as bibliotecas de I/O C e C++ para melhorar o desempenho de operações de I/O.
    ios::sync_with_stdio(false);

    // Desvincula cin de cout para melhorar ainda mais o desempenho das operações de entrada e saída.
    cin.tie(nullptr);

    // Verifica se o número de argumentos passados na linha de comando é igual a 2.
    // Isso é importante porque o programa espera um argumento que especifica o nome do arquivo a ser lido.
    if (argc != 2) {
        // Se o número de argumentos for diferente de 2, imprime uma mensagem de erro explicando o uso correto do programa.
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>\n";
        return 1;  // Retorna 1 para indicar que o programa terminou devido a um erro.
    }

    // Abre o arquivo cujo nome foi passado como argumento na linha de comando.
    ifstream file(argv[1]);

    // Verifica se o arquivo foi aberto com sucesso.
    // Caso contrário, imprime uma mensagem de erro e encerra o programa com código de erro 1.
    if (!file) {
        cerr << "Erro ao abrir o arquivo: " << argv[1] << "\n";
        return 1;
    }

    // Declara uma string para armazenar a primeira linha do arquivo, que deve conter o tamanho do vetor.
    string line;
    getline(file, line);  // Lê a primeira linha do arquivo e a armazena na variável 'line'.

    // Converte a string lida para um número inteiro que representa o tamanho do vetor.
    int size = stoi(line);

    // Declara um vetor de inteiros chamado 'vec' e reserva espaço para 'size' elementos.
    // A reserva de espaço antecipada evita realocações desnecessárias durante as inserções, melhorando a eficiência.
    vi vec;
    vec.reserve(size);

    // Declara uma variável para armazenar temporariamente cada número lido do arquivo.
    int num;

    // Lê o restante do arquivo e armazena cada número no vetor 'vec'.
    // O loop termina quando todos os números tiverem sido lidos.
    while (file >> num) {
        vec.push_back(num);  // Adiciona o número lido ao final do vetor 'vec'.
    }

    // Fecha o arquivo, pois ele não é mais necessário após a leitura dos dados.
    file.close();

    // Imprime o vetor original lido do arquivo para verificação.
    cout << "Vetor original: ";
    print_vector(vec);

    // Insere o valor 42 na posição 5 do vetor, se o tamanho do vetor for maior que 5.
    // Isso demonstra o uso do método insert para adicionar elementos em uma posição específica do vetor.
    if (vec.size() > 5) {
        vec.insert(vec.begin() + 5, 42);
        cout << "Após insert na posição 5: ";
        print_vector(vec);
    }

    // Remove o último elemento do vetor usando o método pop_back, se o vetor não estiver vazio.
    // Isso é útil para reduzir o tamanho do vetor removendo o elemento mais recente.
    if (!vec.empty()) {
        vec.pop_back();
        cout << "Após pop_back: ";
        print_vector(vec);
    }

    // Remove o elemento na posição 3 do vetor, se o tamanho do vetor for maior que 3.
    // Isso demonstra o uso do método erase para remover elementos de uma posição específica.
    if (vec.size() > 3) {
        vec.erase(vec.begin() + 3);
        cout << "Após erase na posição 3: ";
        print_vector(vec);
    }

    // Cria um novo vetor 'vec2' com 5 elementos, todos inicializados com o valor 7.
    // Isso é útil para criar um vetor com valores padrão.
    vi vec2(5, 7);
    cout << "Vetor com 5 elementos (valor 7): ";
    print_vector(vec2);

    // Redimensiona o vetor 'vec2' para conter 10 elementos.
    // Os novos elementos serão inicializados com o valor padrão do tipo, que para int é 0.
    vec2.resize(10);
    cout << "Após resize para 10 elementos: ";
    print_vector(vec2);

    // Gera uma semente para o gerador de números aleatórios baseada no tempo atual do sistema.
    uint seed = static_cast<uint>(chrono::high_resolution_clock::now().time_since_epoch().count());

    // Cria um gerador Mersenne Twister para gerar números pseudoaleatórios.
    mt19937_gen generator(seed);

    // Define uma distribuição uniforme de inteiros entre 1 e 100.
    // Cada número gerado pelo 'generator' estará dentro desse intervalo.
    uniform_int_distribution<int> distribution(1, 100);

    // Preenche o vetor 'vec2' com valores aleatórios gerados pela distribuição uniforme.
    for (size_t i = 0; i < vec2.size(); ++i) {
        vec2[i] = distribution(generator);
    }

    // Imprime o vetor 'vec2' após ter sido preenchido com valores aleatórios.
    cout << "Após preencher com valores aleatórios: ";
    print_vector(vec2);

    // Ordena o vetor 'vec2' em ordem crescente usando o algoritmo padrão sort.
    sort(vec2.begin(), vec2.end());
    cout << "Após sort: ";
    print_vector(vec2);

    // Exemplo de matriz utilizando um vetor de vetores (2D)
    // Aqui, criamos uma matriz de 2x2, onde cada elemento é inicializado com o valor 1.
    int linhas = 2, colunas = 2;
    vvi matriz(linhas, vi(colunas));

    // Preenche a matriz com o valor 1 em todas as suas posições.
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            matriz[i][j] = 1;
        }
    }

    // Imprime a matriz linha por linha.
    // A matriz é um vetor de vetores, onde cada linha da matriz é um vetor.
    cout << "Matriz:\n";
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;  // Indica que o programa terminou com sucesso.
}