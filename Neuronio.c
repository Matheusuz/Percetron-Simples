#include <stdio.h>
#include "Neuronio.h"

//Dados de treinamento do algoritmo
double entradas[4][3] = {{bias,0.0,0.0},{bias,0.0,1.0},{bias,1.0,0.0},{bias,1.0,1.0}};
double saidas[4] = {0.0,0.0,0.0,1.0};

//Como trata-se um classificador binário/linear a função degrau é perfeita essa ocasião
double funcao_degrau(double valor){
    if(valor <= 0)
        return 0.0;
    else    
        return 1.0;
}

//Inializando os pesos do neurônio, nesse caso pode ser inicializado com valores aleatórios ou nulo, por opção escolhi a última
void inicializaPesos(Neuronio *neuronio){
    for(unsigned short int i = 0; i < num_entradas; i++)
        (*neuronio).pesos[i] = 0.0;
       //(*neuronio).pesos[i] = (double) rand() / RAND_MAX;
}

//Simplesmente imprimi os pesos do neurônio
void imprimeDados(Neuronio *neuronio){
    printf("Pesos para cada entrada : ");
    for(unsigned short int i = 0; i < num_entradas; i++){
        if(i != num_entradas - 1)
            printf("%lf,",(*neuronio).pesos[i]);
        else
            printf("%lf\n",(*neuronio).pesos[i]);
    }
}

//Realiza o calculo da soma
double somatorio(Neuronio *neuronio,int indice){
    double soma = 0.0;
    for(unsigned short int i = 0; i < num_entradas; i++)
        soma += entradas[indice][i] * (*neuronio).pesos[i];
    return soma;
}

//Atualiza todos os pesos do neurônios de acordo com o erro
void atualizaPesos(Neuronio *neuronio,int indice){
    double valor_calculado = somatorio(&(*neuronio),indice);

    double erro = saidas[indice] - funcao_degrau(valor_calculado);
    printf("O valor da soma eh : %lf, a saida espera eh : %lf, a saida gerada eh : %lf, o erro eh : %lf\n",valor_calculado,saidas[indice],funcao_degrau(valor_calculado),erro);
    
    for(unsigned short int i = 0; i < num_entradas; i++)
        (*neuronio).pesos[i] = (*neuronio).pesos[i] + erro * entradas[indice][i];
}