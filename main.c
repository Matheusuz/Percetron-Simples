/*
    Autor : Matheus Yasuo Ribeiro Utino

    Trata-se um Perceptron composto por uma única camada e um único neurônio, apesar da sua simplicidade é um bom classificador linear/binário para exemplo mais simplistas.
    Nesse caso ocorre a classificação do mode de porta AND. Rapidamente o modelo encontra os pesos necessários para sua convergência.
    Obs1 : Todos as funções recebem os parâmetros por referência para economia de memória
    Obs2 : O bias é tratado como um dado de entrada (na forma matricial facilitaria, mas é um tanto quanto indiferente)
    Obs3 : Devido a simplicidade os valores inteiros foram declarados como unsigned short int, pois não será utilizado mais que isso
*/

//Importando as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Neuronio.h"

#define num_epocas 6 


int main(int argc, char const *argv[])
{
    Neuronio neuronio; 
    srand((unsigned)time(NULL)); //Para sempre gerar números aleatórios diferentes

    inicializaPesos(&neuronio);
    imprimeDados(&neuronio);

    for(unsigned short int i = 0; i < num_epocas; i++){
        printf("Epoca %d\n\n",i + 1);
        for(unsigned short int j = 0; j < 4; j++){
            atualizaPesos(&neuronio,j);
            imprimeDados(&neuronio);
        }
        printf("\n");
    }

    return 1;
}
