#include <iostream>
#include <thread>
#include <vector>
#include <random>


int main(int argc, char *argv[]) {

    const int N = argv[1];
    std::vector<std::vector<int>> matriz1(N, std::vector<int>(N));
    std::vector<std::vector<int>> matriz2(N, std::vector<int>(N));
    std::vector<std::vector<int>> resultado(N, std::vector<int>(N));

    // Gerar números aleatórios que preencherão a matriz
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100); // entre 1 e 100

    // preencher a matriz1
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz1[i][j] = distrib(gen);
        }
    }

    // preencher matriz2
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz2[i][j] = distrib(gen);
        }
    }

    // Multiplicação de matriz por matriz por linha
    auto inicio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            resultado[i][j] = matriz1[i][j] * matriz2[i][j];


    return 0;
}