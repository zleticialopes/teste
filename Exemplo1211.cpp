/*
Exemplo1211 - v0.0. - 28/05/2023
Author: Leticia de Oliveira Lopes
*/

// dependencias
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

// ----------------------------------------------- definicoes globais

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )

// ----------------------------------------------- classes / pacotes
#include "matriz.hpp"
using namespace std;

// ----------------------------------------------- metodos
void Exemplo1211()
{
    int lin, col, inicio, fim;

    cout << "Digite a quantidade de linhas da matriz: " << endl;
    cin >> lin;
    cout << "Digite a quantidade de colunas da matriz: " << endl;
    cin >> col;

    cout << "Digite o valor inicial do intervalo: " << endl;
    cin >> inicio;
    cout << "Digite o valor final do intervalo: " << endl;
    cin >> fim;

    matriz minhaMatriz(lin, col);
    minhaMatriz.gerarInt(inicio, fim);
    minhaMatriz.gravarEmArquivo("DADOS.TXT");
}

void Exemplo1212()
{
    int k;

    matriz matriz1 = matriz::lerArquivo("DADOS1.TXT");

    cout << "Digite um numero inteiro para multiplicar todos os valores da matriz: " << endl;
    cin >> k;

    matriz matriz2 = matriz1.escalar(k);

    cout << "Matriz escalada: " << endl;
    matriz2.gravarEmArquivo("MATRIZ_ESCALADA.TXT");
}

int main()
{
    int opcao = 0;

    do
    {
        cout << "EXEMPLO1111 - Programa - v0.0 " << endl;

        cout << "Aluna: Leticia de Oliveira Lopes\tMatricula: 781243" << endl;

        cout << "Opcoes       " << endl;
        cout << "0 - parar    " << endl;
        cout << "11 - ler, gerar e armazenar elementos em matriz e grava-los em um arquivo " << endl;
        cout << "12 - escalar uma matriz, multiplicando todos os seus valores por uma k " << endl;
        cout << "13 - testar se uma matriz e uma matriz identidade " << endl;
        cout << "14 - testar a igualdade de duas matrizes " << endl;
        cout << "15 - somar duas matrizes e mostrar o resultado " << endl;
        cout << "16 - " << endl;
        cout << "17 - " << endl;
        cout << "18 - " << endl;
        cout << "19 - " << endl;
        cout << "20 - " << endl;

        cout << endl
             << "Entrar com uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 11:
            Exemplo1211();
            break;

        case 12:
            Exemplo1212();
            break;

        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        }
    } while (opcao != 0);

    return 0;
}

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao
Data
Modificacao
esboco
---------------------------------------------- testes
Versao          Teste
0.1               28/05
0.1               01. ( OK )
identificacao de programa
*/