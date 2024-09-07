#include <iostream>   // Biblioteca para opera��es de entrada e sa�da padr�o
#include <fstream>    // Biblioteca para opera��es de leitura e escrita em arquivos
#include <vector>     // Biblioteca para utilizar a estrutura de dados vector
#include <string>     // Biblioteca para manipula��o de strings
#include <algorithm>  // Biblioteca para algoritmos padr�o, como sort
#include <random>     // Biblioteca para gera��o de n�meros aleat�rios
#include <chrono>     // Biblioteca para manipula��o de tempo e rel�gio de alta resolu��o

// Uso de `using` para reduzir a digita��o de tipos longos
using namespace std;

using vi = vector<int>;              // Alias para `vector<int>`
using vvi = vector<vector<int>>;     // Alias para `vector<vector<int>>`
using uint = unsigned int;           // Alias para `unsigned int`
using mt19937_gen = mt19937;         // Alias para `mt19937`

// Fun��o para imprimir o vetor
// A fun��o print_vector recebe um vetor de inteiros como argumento, mas em vez de passar o vetor diretamente,
// utiliza-se uma refer�ncia constante (const vector<int>& vec). Isso tem v�rias implica��es importantes:
//
// 1. **const**: Garante que o vetor n�o ser� modificado dentro da fun��o. Isso � �til para proteger os dados e
//    garantir que a fun��o serve apenas para leitura.
//
// 2. **vector<int>&**: O uso de refer�ncia (&) evita a c�pia do vetor inteiro quando a fun��o � chamada. 
//    Passar um vetor por valor (sem refer�ncia) resultaria em uma c�pia completa do vetor, o que pode ser
//    ineficiente, especialmente para vetores grandes.
//
// 3. **const vector<int>&**: Combinar const com a refer�ncia permite que a fun��o seja eficiente 
//    (sem c�pia de dados) e segura (sem modifica��o dos dados originais).
//
// O uso deste padr�o � comum em C++ quando se deseja passar grandes estruturas de dados para fun��es que n�o
// precisam modificar esses dados.
void print_vector(const vi& vec) {
    // Itera sobre cada elemento do vetor utilizando um la�o for com itera��o por �ndice
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";  // Acessa o elemento no �ndice `i` e o imprime
    }
    // Imprime uma nova linha ap�s todos os elementos terem sido impressos
    cout << endl;
}

int main(int argc, char* argv[]) {
    // Desativa a sincroniza��o entre as bibliotecas de I/O C e C++ para melhorar o desempenho de opera��es de I/O.
    ios::sync_with_stdio(false);

    // Desvincula cin de cout para melhorar ainda mais o desempenho das opera��es de entrada e sa�da.
    cin.tie(nullptr);

    // Verifica se o n�mero de argumentos passados na linha de comando � igual a 2.
    // Isso � importante porque o programa espera um argumento que especifica o nome do arquivo a ser lido.
    if (argc != 2) {
        // Se o n�mero de argumentos for diferente de 2, imprime uma mensagem de erro explicando o uso correto do programa.
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>\n";
        return 1;  // Retorna 1 para indicar que o programa terminou devido a um erro.
    }

    // Abre o arquivo cujo nome foi passado como argumento na linha de comando.
    ifstream file(argv[1]);

    // Verifica se o arquivo foi aberto com sucesso.
    // Caso contr�rio, imprime uma mensagem de erro e encerra o programa com c�digo de erro 1.
    if (!file) {
        cerr << "Erro ao abrir o arquivo: " << argv[1] << "\n";
        return 1;
    }

    // Declara uma string para armazenar a primeira linha do arquivo, que deve conter o tamanho do vetor.
    string line;
    getline(file, line);  // L� a primeira linha do arquivo e a armazena na vari�vel 'line'.

    // Converte a string lida para um n�mero inteiro que representa o tamanho do vetor.
    int size = stoi(line);

    // Declara um vetor de inteiros chamado 'vec' e reserva espa�o para 'size' elementos.
    // A reserva de espa�o antecipada evita realoca��es desnecess�rias durante as inser��es, melhorando a efici�ncia.
    vi vec;
    vec.reserve(size);

    // Declara uma vari�vel para armazenar temporariamente cada n�mero lido do arquivo.
    int num;

    // L� o restante do arquivo e armazena cada n�mero no vetor 'vec'.
    // O loop termina quando todos os n�meros tiverem sido lidos.
    while (file >> num) {
        vec.push_back(num);  // Adiciona o n�mero lido ao final do vetor 'vec'.
    }

    // Fecha o arquivo, pois ele n�o � mais necess�rio ap�s a leitura dos dados.
    file.close();

    // Imprime o vetor original lido do arquivo para verifica��o.
    cout << "Vetor original: ";
    print_vector(vec);

    // Insere o valor 42 na posi��o 5 do vetor, se o tamanho do vetor for maior que 5.
    // Isso demonstra o uso do m�todo insert para adicionar elementos em uma posi��o espec�fica do vetor.
    if (vec.size() > 5) {
        vec.insert(vec.begin() + 5, 42);
        cout << "Ap�s insert na posi��o 5: ";
        print_vector(vec);
    }

    // Remove o �ltimo elemento do vetor usando o m�todo pop_back, se o vetor n�o estiver vazio.
    // Isso � �til para reduzir o tamanho do vetor removendo o elemento mais recente.
    if (!vec.empty()) {
        vec.pop_back();
        cout << "Ap�s pop_back: ";
        print_vector(vec);
    }

    // Remove o elemento na posi��o 3 do vetor, se o tamanho do vetor for maior que 3.
    // Isso demonstra o uso do m�todo erase para remover elementos de uma posi��o espec�fica.
    if (vec.size() > 3) {
        vec.erase(vec.begin() + 3);
        cout << "Ap�s erase na posi��o 3: ";
        print_vector(vec);
    }

    // Cria um novo vetor 'vec2' com 5 elementos, todos inicializados com o valor 7.
    // Isso � �til para criar um vetor com valores padr�o.
    vi vec2(5, 7);
    cout << "Vetor com 5 elementos (valor 7): ";
    print_vector(vec2);

    // Redimensiona o vetor 'vec2' para conter 10 elementos.
    // Os novos elementos ser�o inicializados com o valor padr�o do tipo, que para int � 0.
    vec2.resize(10);
    cout << "Ap�s resize para 10 elementos: ";
    print_vector(vec2);

    // Gera uma semente para o gerador de n�meros aleat�rios baseada no tempo atual do sistema.
    uint seed = static_cast<uint>(chrono::high_resolution_clock::now().time_since_epoch().count());

    // Cria um gerador Mersenne Twister para gerar n�meros pseudoaleat�rios.
    mt19937_gen generator(seed);

    // Define uma distribui��o uniforme de inteiros entre 1 e 100.
    // Cada n�mero gerado pelo 'generator' estar� dentro desse intervalo.
    uniform_int_distribution<int> distribution(1, 100);

    // Preenche o vetor 'vec2' com valores aleat�rios gerados pela distribui��o uniforme.
    for (size_t i = 0; i < vec2.size(); ++i) {
        vec2[i] = distribution(generator);
    }

    // Imprime o vetor 'vec2' ap�s ter sido preenchido com valores aleat�rios.
    cout << "Ap�s preencher com valores aleat�rios: ";
    print_vector(vec2);

    // Ordena o vetor 'vec2' em ordem crescente usando o algoritmo padr�o sort.
    sort(vec2.begin(), vec2.end());
    cout << "Ap�s sort: ";
    print_vector(vec2);

    // Exemplo de matriz utilizando um vetor de vetores (2D)
    // Aqui, criamos uma matriz de 2x2, onde cada elemento � inicializado com o valor 1.
    int linhas = 2, colunas = 2;
    vvi matriz(linhas, vi(colunas));

    // Preenche a matriz com o valor 1 em todas as suas posi��es.
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            matriz[i][j] = 1;
        }
    }

    // Imprime a matriz linha por linha.
    // A matriz � um vetor de vetores, onde cada linha da matriz � um vetor.
    cout << "Matriz:\n";
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;  // Indica que o programa terminou com sucesso.
}