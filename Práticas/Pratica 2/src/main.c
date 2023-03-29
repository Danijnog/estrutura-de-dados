//---------------------------------------------------------------------
// Arquivo	: main.c
// Conteudo	: implementacao da função principal e função para ler da linha de comando
// Autor	: Daniel Nogueira Junqueira (danijnog@ufmg.br)
// Historico	: 29/03/2023 - arquivo criado
//---------------------------------------------------

#include "../include/fatorial.h"
#include "../include/fibonacci.h"
#include "../include/tempo.h"

#include "stdio.h"
#include "getopt.h"
#include "stdlib.h"

static int opEscolhida;
int numEscolhido;

void parse_args(int argc, char **argv) {
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
    int aux; //variavel auxiliar
    numEscolhido = -1;
    opEscolhida = -1;

    //getopt() -> função que le argumentos curtos da linha de comando
    // aux = getopt(argc, argv, "a:x");
    while((aux = getopt(argc, argv, "abn:h")) != EOF) //flags a, b, n requerem um argumento, e a flag 'h' de ajuda não requer argumento
    {
        switch(aux)
        {
            case 'a': /* Fatorial */
                opEscolhida = OP_FATORIAL;
                break;
            
            case 'b': /* Fibonacci */
                opEscolhida = OP_FIBONACCI;
                break;

            case 'n': /* Parametro para passar o numero escolhido para se calcular o fatorial ou fibonacci*/
                if(optarg != NULL)
                    numEscolhido = atoi(optarg);
                break;
            
            case 'h': /* Ajuda */
                printf("Ajuda: \n");
                printf("No makefile é passado os seguintes argumentos para o programa: \n");
                printf("-a -> escolhe a operação fatorial \n");
                printf("-b -> escolhe a operação fibonacci \n");
                printf("-n -> escolhe o número que vai ser calculado o fatorial ou fibonacci \n");
                printf("Exemplo: -a -n 5 \n");
            
            default:
                fprintf(stderr, "Opção inválida ou ausente: %c \n", optopt); //para pegarmos a saída de erro
                break;
        }

    }
    
}

int main(int argc, char ** argv) {

    struct rusage start, end; //estrutura para armazenar o tempo de usuario e sistema decorrido
    parse_args(argc, argv); //chamando a função que permite ler da linha de comando

    switch(opEscolhida)
    {
        case OP_FATORIAL:
            getrusage(RUSAGE_SELF, &start); //o inteiro RUSAGE_SELF é uma macro, e aqui damos inicio ao processo da thread atual (Fatorial Recursivo)

            printf("\n-------- Fatorial -------- \n");
            int resultadoFatorialRecursivo = fatorialRecursivo(numEscolhido);
            printf("\nFatorial (Recursivo) de %d: %d\n", numEscolhido, resultadoFatorialRecursivo);
            getrusage(RUSAGE_SELF, &end); //aqui terminamos o processo da thread atual (Fatorial Recursivo) passando o endereço &end do objeto 'rusage' como argumento pra função

            printf("\n-fatorialRecursivo status: \n");
            printf("-Tempo usuário (CPU): %.07f seg, tempo do sistema: %.09f seg\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));


            getrusage(RUSAGE_SELF, &start); //o inteiro RUSAGE_SELF é uma macro, e aqui damos inicio ao processo da próxima thread (Fatorial Iterativo)
            int resultadoFatorialIterativo = fatorialIterativo(numEscolhido);
            printf("\nFatorial (Iterativo) de %d: %d\n", numEscolhido, resultadoFatorialIterativo);
            getrusage(RUSAGE_SELF, &end); //aqui terminamos o processo da thread atual (Fatorial Iterativo) passando o endereço &end do objeto 'rusage' como argumento pra função

            printf("\n-fatorialIterativo status: \n");
            printf("-Tempo usuário (CPU): %.07f seg, tempo do sistema: %.09f seg\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

            printf("---------------------------\n");

            break;


        case OP_FIBONACCI: 
            getrusage(RUSAGE_SELF, &start); //aqui vamos dar início ao processo da thread atual (Fibonacci Recursivo)

            printf("\n-------- Fibonacci -------- \n");
            int resultadoFibonacciRecursivo = fibonacciRecursivo(numEscolhido);
            printf("\nFibonacci (Recursivo) de %d: %d\n", numEscolhido, resultadoFibonacciRecursivo);
            getrusage(RUSAGE_SELF, &end); //aqui terminamos o processo da thread atual (Fibonacci Recursivo) passando o endereço &end do objeto 'rusage' como argumento pra função

            printf("\n-fibonacciRecursivo status: \n");
            printf("-Tempo usuário (CPU): %.07f seg, tempo do sistema: %.09f seg\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

            getrusage(RUSAGE_SELF, &start); //aqui vamos dar início ao processo da próxima thread (Fibonacci Iterativo)
            int resultadoFibonacciIterativo = fibonacciIterativo(numEscolhido);
            printf("\nFibonacci (Iterativo) de %d: %d\n", numEscolhido, resultadoFibonacciIterativo);
            getrusage(RUSAGE_SELF, &end); //aqui terminamos o processo da thread atual (Fibonacci Iterativo) passando o endereço &end do objeto 'rusage' como argumento pra função

            printf("\n-fibonacciIterativo status: \n");
            printf("-Tempo usuário (CPU): %.07f seg, tempo do sistema: %.09f seg\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

            printf("---------------------------\n");

            break;

    }
    return 0;
}