#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <tamanho da matriz N>" << std::endl;
        return 1;
    }

    const int N = std::atoi(argv[1]);
    const int BLOCK_SIZE = std::atoi(argv[2]);
    std::vector<std::vector<int>> matriz1(N, std::vector<int>(N));
    std::vector<std::vector<int>> matriz2(N, std::vector<int>(N));
    std::vector<std::vector<int>> resultado(N, std::vector<int>(N, 0));

    // Configuração do gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    // Preencher matriz1 e matriz2 com valores aleatórios
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz1[i][j] = distrib(gen);
            matriz2[i][j] = distrib(gen);
        }
    }


    auto inicio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < std::min(j + BLOCK_SIZE, N); ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout << "Tempo de execução (blocagem): " << duracao.count() << " microsegundos" << std::endl;

    return 0;
}
