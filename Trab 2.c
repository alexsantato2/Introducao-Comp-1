#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
    int num, tentativa, cont;
   
        // GERA UM NUMERO ALEATORIO ENTRE 0 E 100
        srand(time(NULL));
        num = rand() % 99 + 1;
        cont = 0;

        // PRIMEIRA TENTATIVA       
        printf("Tente acertar um numero entre 0 e 100, não considerando-os: ");
        scanf("%d", &tentativa);
        cont++;
       
        // CONTADOR DE TENTATIVAS
        while (tentativa != num) {
            if (tentativa < num) {
                printf("Numero menor, tente novamente: ");
            }
            else {
                printf("Numero maior, tente novamente: ");
            }
            scanf("%d", &tentativa);
            cont++;
        }

        // FINALIZA COM A QUANTIDADE DE TENTATIVAS ATE O ACERTO
        printf("\nParabens, voce acertou! O numero era %d\n", num);
        printf("Tentativas feitas: %d", cont);
}
