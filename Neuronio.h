//Definindo as constante
#define num_entradas 3
#define bias 1.0


//Criando a estrutra do nosso neurônio (como trata-se de um modelo simples ele contêm apenas os vetores de pessos)
struct neuronio
{
    double pesos[num_entradas];
};

typedef struct neuronio Neuronio;

//Protótipos das funções que podem ser chamadas pelo usuário
void inicializaPesos(Neuronio *neuronio);
void imprimeDados(Neuronio *neuronio);
void atualizaPesos(Neuronio *neuronio,int indice);
