/*
Exemplo1202 - v0.0. - 04/06/2023
Author: Leticia de Oliveira Lopes
Matricula: 781243
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres

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

#include "mymatrix.hpp"
using namespace std;

// ----------------------------------------------- metodos

/**
Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    // definir dados
    Matrix<int> int_matrix(2, 2, 0);
    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);
    // identificar
    cout << "\nEXEMPLO1210 - Method01 - v0.0\n"
         << endl;
    // mostrar dados
    int_matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
Method02.
*/
void method02()
{
    // definir dados
    Matrix<int> matrix(2, 2, 0);
    // identificar
    cout << endl
         << "EXEMPLO1210 - Method02 - v0.0" << endl;
    // ler dados
    matrix.read();
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method02 ( )


// ----------------------------------------------- acao principal

/*
Funcao principal.
@return codigo de encerramento
*/
int main(int argc, char **argv)
{
    // definir dado
    int opcao = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1202 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes       " << std::endl;
        cout << "1 - Method01" << std::endl;
        cout << "2 - Method02" << std::endl;

        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> opcao;

        // escolher acao
        switch (opcao)
        {
        case 1:
            method01();
            break;

        case 2:
            method02();
            break;

        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        } // fim escolher
    } while (opcao != 0);
    // encerrar

    pause("Apertar ENTER para terminar");

    return (0);
} // fim main( )

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
0.1               04/06
0.1               01. ( OK )
identificacao de programa
*/