#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*QUEST�O PROVA PR�TICA:
    Desenvolva um algoritmo recursivo para descobrir se uma palavra � um pal�ndromo, lembrando que:
- Caso a palavra seja vazia ou contenha somente uma letra, ela � um pal�ndromo.
- Caso a palavra tenha mais de um caractere, deve-se comparar a primeira letra com a �ltima letra da palavra.
- Se a primeira e a �ltima letra s�o distintas, ent�o a palavra n�o � um pal�ndromo. Caso contr�rio, a segunda letra deve ser comparada com a pen�ltima letra, e assim sucessivamente.*/


//RECURSIVO
//verificando se � um pal�ndromo:
int palindromoRecursivo(char *palavra, int inicio, int fim) {

    if (inicio >= fim) { //caso in�cio (0) seja maior ou igual que o fim, � palavra vazia ou com apenas uma letra
        return 1; //retorna que � um pal�ndromo
    }

    char c1 = tolower(palavra[inicio]); //aqui usei a fun��o "tolower()" da biblioteca "ctype.h" para converter todas as letras para min�sculo para n�o ter nenhum erro
    char c2 = tolower(palavra[fim]); //aqui usei a fun��o "tolower()" da biblioteca "ctype.h" para converter todas as letras para min�sculo para n�o ter nenhum erro

    if (c1 != c2) { //aqui verifico se a primeira letra � diferente da �ltima letra
        return 0; //caso sejam diferentes, sabemos que n�o � um pal�ndromo, como consta no cabe�alho da atividade
    } else { //se a primeira letra for igual a �ltima letra
        return palindromoRecursivo(palavra, inicio + 1, fim - 1); /*voltamos ao in�cio da fun��o para comparar se a segunda letra � igual a pen�ltima
                                                                    sigo assim at� que aconte�a o "inicio>=fim"*/
    }
}

//ITERATIVO
//verificando se � um pal�ndromo:
int palindromoIterativo(char *palavra) {
    int inicio = 0; //primeira letra da palavra come�a no 0
    int fim = strlen(palavra) - 1; //comprimento da palavra (string) - 1 para termos o ind�ce da �ltima letra correto

    while (inicio <= fim) { //enquanto in�cio for igual ou menor que fim, �ndice do in�cio da palavra for menor ou igual que o �ndice do final da palavra

    char c1 = tolower(palavra[inicio]); //aqui usei a fun��o "tolower()" da biblioteca "ctype.h" para converter todas as letras para min�sculo para n�o ter nenhum erro
    char c2 = tolower(palavra[fim]); //aqui usei a fun��o "tolower()" da biblioteca "ctype.h" para converter todas as letras para min�sculo para n�o ter nenhum erro

        if (c1 != c2) { //aqui verifico se a primeira letra � diferente da �ltima letra
            return 0; //caso sejam diferentes, sabemos que n�o � um pal�ndromo, como consta no cabe�alho da atividade
        }

        inicio++; //incrementa 1 para comparar a pr�xima letra
        fim--; //decrementa 1 para voltar uma letra do fim
    }

    return 1; //quando o �ndice do in�cio da palavra for maior que o �ndice do final da palavra, retorna que � um pal�ndromo
}

//EXECUTANDO
int main() {
    setlocale(LC_ALL, "Portuguese");
    char palavra[20]; //limitei a uma palavra com 20 caracteres

    printf("----- BEM-VINDO AO DETECTOR DE PAL�NDROMO CRIADO POR GABRIEL MACHADO! -----\n");
    printf("\n");
    printf("Vamos l�! Digite uma palavra: ");
    printf("\n");
    scanf("%s", palavra);
    printf("\n");

    //utilizando o RECURSIVO para verificar
    if (palindromoRecursivo(palavra, 0, strlen(palavra) - 1)) {
        printf("%s � um pal�ndromo (usando o algoritmo recursivo).\n", palavra);
    } else {
        printf("%s n�o � um pal�ndromo (usando o algoritmo recursivo).\n", palavra);
    }

    //utilizando o ITERATIVO para verificar
    if (palindromoIterativo(palavra)) {
        printf("%s � um pal�ndromo (usando o algoritmo iterativo).\n", palavra);
    } else {
        printf("%s n�o � um pal�ndromo (usando o algoritmo iterativo).\n", palavra);
    }

    return 0;
}

