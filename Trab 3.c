#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    //Funcao que verifica se numeros coincidentes entre dois vetores ja foram encontrados anteriormente
    //Recebe o numero a ser procurado, quantos numeros iguais ja foram encontrados e vetor a ser vasculhado
    bool existencia(int num, int k, int *pointer);

    //Coloca os valores em ordem crescente
    void ordemCrescente(int *pointer, int quantidade);

    //Pede o tamanho dos vetores
    int m, n;
    printf("Digite um valor para m: ");
    scanf(" %d", &m);
    printf("Digite um valor para n: ");
    scanf(" %d", &n);

    //Cria os vetores com alocacao dinamica
    int *pointer1 = (int *) calloc(m, sizeof(int));
    int *pointer2 = (int *) calloc(n, sizeof(int));

    //Recebe os vetores
    printf("\nVETOR 1 (m posicoes):\n");
    for (int i = 0; i < m; i++) {
        printf("Digite vet1[%d]: ", i+1);
        scanf(" %d", (pointer1 + i));
    }
    printf("\nVETOR 2 (n posicoes):\n");
    for (int i = 0; i < n; i++) {
        printf("Digite vet2[%d]: ", i+1);
        scanf(" %d", (pointer2 + i));
    }

    //Encontra o tamanho do menor vetor
    int menor;
    if (m < n) {
        menor = m;
    } else {
        menor = n;
    }

    //Aloca memoria com base no menor vetor
    int *pointer = (int *) calloc(menor, sizeof(int));

    //Variavel para calcular quantidade de numeros iguais
    int iguais = 0;

    //Verifica se tem numeros iguais entre os vetores
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(pointer1 + i) == *(pointer2 + j)) {
                
                //Verifica se o numero igual ja foi localizado anteriormente no vetor resultante
                //false: nao encontrado (OK); true: encontrado (Cancelar)
                if (!(existencia(*(pointer1 + i), iguais, pointer))) {
                    *(pointer+iguais) = *(pointer1 + i);
                    iguais++;
                }

            }
        }
    }

    //Deixa o vetor dinamico apenas com o tamanho necessario
    pointer = realloc(pointer, iguais * sizeof(int));

    //Coloca em ordem crescente o vetor resultante
    ordemCrescente(pointer, iguais);

    //Imprime o vetor resultante de numeros coincidentes
    printf("\nVETOR RESULTANTE:\n");
    for (int i = 0; i < iguais; i++) {
        printf("%d\n", *(pointer+i));
    }
    printf("\n");

    //Libera o espaco de todos os vetores
    free(pointer);
    free(pointer1);
    free(pointer2);

    return 0;
}

bool existencia (int num, int k, int *pointer) {
    for (int i = 0; i < k; i++) {
        if (*(pointer+i) == num) {
            return true;
        }
    }
    return false;
}

void ordemCrescente(int *pointer, int quantidade) {

    int temp;
    for(int i = 0; i < quantidade; i++) {
        for(int j = i; j < quantidade; j++) {
            if(*(pointer+i) > *(pointer+j)) {
                temp = *(pointer+i);
                *(pointer+i) = *(pointer+j);
                *(pointer+j) = temp;
            }
        }
    }

}