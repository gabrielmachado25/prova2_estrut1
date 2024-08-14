#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*QUESTÃO PROVA PRÁTICA:
    Desenvolva um algoritmo recursivo para descobrir se uma palavra é um palíndromo, lembrando que:
- Caso a palavra seja vazia ou contenha somente uma letra, ela é um palíndromo.
- Caso a palavra tenha mais de um caractere, deve-se comparar a primeira letra com a última letra da palavra.
- Se a primeira e a última letra são distintas, então a palavra não é um palíndromo. Caso contrário, a segunda letra deve ser comparada com a penúltima letra, e assim sucessivamente.*/


//RECURSIVO
//verificando se é um palíndromo:
int palindromoRecursivo(char *palavra, int inicio, int fim) {

    if (inicio >= fim) { //caso início (0) seja maior ou igual que o fim, é palavra vazia ou com apenas uma letra
        return 1; //retorna que é um palíndromo
    }

    char c1 = tolower(palavra[inicio]); //aqui usei a função "tolower()" da biblioteca "ctype.h" para converter todas as letras para minúsculo para não ter nenhum erro
    char c2 = tolower(palavra[fim]); //aqui usei a função "tolower()" da biblioteca "ctype.h" para converter todas as letras para minúsculo para não ter nenhum erro

    if (c1 != c2) { //aqui verifico se a primeira letra é diferente da última letra
        return 0; //caso sejam diferentes, sabemos que não é um palíndromo, como consta no cabeçalho da atividade
    } else { //se a primeira letra for igual a última letra
        return palindromoRecursivo(palavra, inicio + 1, fim - 1); /*voltamos ao início da função para comparar se a segunda letra é igual a penúltima
                                                                    sigo assim até que aconteça o "inicio>=fim"*/
    }
}

//ITERATIVO
//verificando se é um palíndromo:
int palindromoIterativo(char *palavra) {
    int inicio = 0; //primeira letra da palavra começa no 0
    int fim = strlen(palavra) - 1; //comprimento da palavra (string) - 1 para termos o indíce da última letra correto

    while (inicio <= fim) { //enquanto início for igual ou menor que fim, índice do início da palavra for menor ou igual que o índice do final da palavra

    char c1 = tolower(palavra[inicio]); //aqui usei a função "tolower()" da biblioteca "ctype.h" para converter todas as letras para minúsculo para não ter nenhum erro
    char c2 = tolower(palavra[fim]); //aqui usei a função "tolower()" da biblioteca "ctype.h" para converter todas as letras para minúsculo para não ter nenhum erro

        if (c1 != c2) { //aqui verifico se a primeira letra é diferente da última letra
            return 0; //caso sejam diferentes, sabemos que não é um palíndromo, como consta no cabeçalho da atividade
        }

        inicio++; //incrementa 1 para comparar a próxima letra
        fim--; //decrementa 1 para voltar uma letra do fim
    }

    return 1; //quando o índice do início da palavra for maior que o índice do final da palavra, retorna que é um palíndromo
}

//EXECUTANDO
int main() {
    setlocale(LC_ALL, "Portuguese");
    char palavra[20]; //limitei a uma palavra com 20 caracteres

    printf("----- BEM-VINDO AO DETECTOR DE PALÍNDROMO CRIADO POR GABRIEL MACHADO! -----\n");
    printf("\n");
    printf("Vamos lá! Digite uma palavra: ");
    printf("\n");
    scanf("%s", palavra);
    printf("\n");

    //utilizando o RECURSIVO para verificar
    if (palindromoRecursivo(palavra, 0, strlen(palavra) - 1)) {
        printf("%s é um palíndromo (usando o algoritmo recursivo).\n", palavra);
    } else {
        printf("%s não é um palíndromo (usando o algoritmo recursivo).\n", palavra);
    }

    //utilizando o ITERATIVO para verificar
    if (palindromoIterativo(palavra)) {
        printf("%s é um palíndromo (usando o algoritmo iterativo).\n", palavra);
    } else {
        printf("%s não é um palíndromo (usando o algoritmo iterativo).\n", palavra);
    }

    return 0;
}

