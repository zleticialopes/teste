/*
matriz.hpp - v0.0. - 10/06/2023
Author: Leticia de Oliveira Lopes
*/

// bibliotecas necessarias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw;

#include <stdlib.h>

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo

#include <cstdlib>

#include <ctime>

using namespace std;

class matriz
{
private:
    int lin;
    int col;
    int **data;

public:
    matriz();
    matriz(int lin, int col);
    ~matriz();
    void gerarInt(int inicio, int fim);
    void gravarEmArquivo(string nomeArq);
    static matriz lerArquivo(const string &nomeArq);
    matriz escalar(const int k);
    void imprimir() const;
};

matriz::matriz()
{
    lin = 0;
    col = 0;
    data = nullptr;
}

matriz::matriz(int lin, int col)
{
    this->lin = lin;
    this->col = col;

    data = new int *[lin];
    for (int i = 0; i < lin; i++)
    {
        data[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            data[i][j] = 0;
        }
    }
}

matriz::~matriz()
{
    if (data != nullptr)
    {
        for (int x = 0; x < lin; x++)
        {
            delete[] data[x];
        }

        delete[] data;
    }
}

void matriz::gerarInt(int inicio, int fim)
{
    srand(time(NULL));

    if (inicio >= 1 && fim <= 100)
    {
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int num = (rand() % (fim - inicio + 1)) + inicio;
                data[i][j] = num;
            }
        }
    }

    else
    {
        cout << "ERRO: nao foi possivel gerar uma matriz de numeros aleatorios" << endl;
        return;
    }
}

void matriz::gravarEmArquivo(const string nomeArq)
{
    ofstream arq;
    arq.open(nomeArq);

    if (arq.is_open())
    {
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int num = data[i][j];
                arq << num << endl;
            }
        }

        arq.close();

        cout << "Dados gravados em " << nomeArq << endl;
    }

    else
    {
        cout << "Erro: nao foi possivel gravar o arquivo em " << nomeArq << endl;
    }
}

matriz matriz::lerArquivo(const string &nomeArq)
{
    matriz matriz2;

    ifstream arq;
    arq.open(nomeArq);

    if (arq.is_open())
    {
        arq >> matriz2.lin >> matriz2.col;

        matriz2.data = new int *[matriz2.lin];

        for (int i = 0; i < matriz2.lin; i++)
        {
            matriz2.data[i] = new int[matriz2.col];
            for (int j = 0; j < matriz2.col; j++)
            {
                arq >> matriz2.data[i][j];
            }
        }

        arq.close();
        matriz2.gravarEmArquivo("ARQLIDO.TXT");
        cout << "Dados lidos! " << endl;
    }

    else
    {
        cout << "ERRO: nao foi possivel ler o arquivo!" << endl;
    }
    return matriz2;
}

matriz matriz::escalar(const int k)
{
    matriz matrizEscalar(lin, col);

    matrizEscalar.lin = lin;
    matrizEscalar.col = col;

    matrizEscalar.data = new int *[lin];
    for (int i = 0; i < lin; i++)
    {
        matrizEscalar.data[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            matrizEscalar.data[i][j] = data[i][j] * k;
        }
    }

    return matrizEscalar;
}

void matriz::imprimir() const
{

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
