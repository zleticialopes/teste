/*
minhaMatriz.hpp - v0.0. - 04/06/2023
Author: Leticia de Oliveira Lopes
*/

#ifndef _MINHAMATRIZ_HPP_
#define _MINHAMATRIZ_HPP_

// dependencias
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class minhaMatriz
{
private:
    int M;
    int N;
    int matriz[100][100];

public:
    void setM(int value);
    void setN(int value);
    void gerarInt(int M, int N, int inicio, int fim);
    static void gravarMatrizEmArq(int M, int N, int matriz[][100]);
    static minhaMatriz lerMatrizArq(const std::string &nomeArq);
    static void gravarMatrizEmArq2(int M, int N, int matriz[][100], const std::string &nomeArquivo);
    minhaMatriz escalar(int k) const;
    void imprimirMatriz() const;
    int getM() const;
    int getN() const;
    int (*getMatriz())[100];
    bool identidade() const;
    bool operator==(const minhaMatriz &novaMatriz) const;
    minhaMatriz somar(const minhaMatriz &novaMatriz) const;
};

void minhaMatriz::gerarInt(int M, int N, int inicio, int fim)
{
    srand(time(NULL));

    std::ofstream arq("DADOS.TXT");

    if (!arq)
    {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = inicio + rand() % (fim - inicio + 1);
            arq << matriz[i][j] << " ";
        }

        arq << std::endl;
    }

    gravarMatrizEmArq(M, N, matriz);
}

void minhaMatriz::gravarMatrizEmArq(int M, int N, int matriz[][100])
{
    std::ofstream arq("DADOS.TXT");

    if (!arq)
    {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    arq << (M*N) << std::endl;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arq << matriz[i][j] << " ";
        }
        arq << std::endl;
    }

    arq.close();

    std::cout << "Matriz gravada com sucesso!" << std::endl;
}

// a partir daqui tá dando tudo errado
minhaMatriz minhaMatriz::lerMatrizArq(const std::string &nomeArq)
{
    std::ifstream arq(nomeArq);

    if (!arq)
    {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return minhaMatriz();
    }

    int M, N;
    arq >> M >> N;

    minhaMatriz matrizObj;
    matrizObj.setM(M);
    matrizObj.setN(N);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arq >> matrizObj.matriz[i][j];
        }
    }

    arq.close();

    std::cout << "Matriz lida com sucesso!" << std::endl;

    return matrizObj;
}

void minhaMatriz::gravarMatrizEmArq2(int M, int N, int matriz[][100], const std::string &nomeArquivo)
{
    std::ofstream arq(nomeArquivo);

    if (!arq)
    {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    arq << (M * N) << std::endl;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arq << matriz[i][j] << " ";
        }
        arq << std::endl;
    }

    arq.close();

    std::cout << "Matriz gravada com sucesso no arquivo " << nomeArquivo << "!" << std::endl;
}

minhaMatriz minhaMatriz::escalar(int k) const
{
    minhaMatriz matrizEscalada;
    matrizEscalada.M = M;
    matrizEscalada.N = N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizEscalada.matriz[i][j] = matriz[i][j] * k;
        }
    }

    return matrizEscalada;
}

void minhaMatriz::imprimirMatriz() const
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int minhaMatriz::getM() const
{
    return M;
}

int minhaMatriz::getN() const
{
    return N;
}

int (*minhaMatriz::getMatriz())[100]
{
    return matriz;
}

void minhaMatriz::setM(int value)
{
    M = value;
}

void minhaMatriz::setN(int value)
{
    N = value;
}
// termina onde tá dando tudo errado

bool minhaMatriz::identidade() const
{
    if (M != N)
    {
        return false; 
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j && matriz[i][j] != 1)
            {
                return false; 
            }
            else if (i != j && matriz[i][j] != 0)
            {
                return false; 
            }
        }
    }

    return true;
}

bool minhaMatriz::operator==(const minhaMatriz &novaMatriz) const
{
    if (M != novaMatriz.M || N != novaMatriz.N)
    {
        return false; 
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matriz[i][j] != novaMatriz.matriz[i][j])
            {
                return false; 
            }
        }
    }

    return true;
}

minhaMatriz minhaMatriz::somar(const minhaMatriz &novaMatriz) const
{
    minhaMatriz matrizSoma;
    matrizSoma.setM(M);
    matrizSoma.setN(N);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizSoma.matriz[i][j] = matriz[i][j] + novaMatriz.matriz[i][j];
        }
    }

    return matrizSoma;
}



#endif
