#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int main() {
    const int N = 1000;
    std::vector<std::vector<int>> matriz1(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> matriz2(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> resultado(N, std::vector<int>(N, 0));

    // Medir tempo de execução
    auto inicio = std::chrono::high_resolution_clock::now();

    // Multiplicação percorrendo por coluna primeiro
    for (int j = 0; j < N; ++j) {      // Percorre as colunas primeiro
        for (int i = 0; i < N; ++i) {  // Depois percorre as linhas
            resultado[i][j] = 0;
            for (int k = 0; k < N; ++k) {  // Percorre os elementos da linha de A e coluna de B
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "Tempo de execução (percorrendo por coluna): " << duracao.count() << " ms" << std::endl;

    return 0;
}
