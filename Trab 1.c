#include <stdio.h>
#include <math.h>

void main() {
   
    // CINCO NUMEROS, OPCAO DO MENU, RESULTADO DA OPERACAO E SABER SE DEVE REPETIR OU NAO O PROGRAMA
    float x[5];
    int opcao, final;
    float resultado;
   
   
    // PERGUNTA SE QUER REPETIR AO FINAL DO PROGRAMA
    do {
        // MENU DE SELECAO DO PROGRAMA
        do {
            
            printf("Escolha qual calculo deseja realizar:\n");
            printf("   (1) Media aritmetica simples\n");
            printf("   (2) Media ponderada\n");
            printf("   (3) Desvio padrao\n");
            printf("   (4) Maior valor\n");
            printf("   (5) Menor valor\n");
       
            scanf("%d", &opcao);
            printf("\n");
           
        } while (opcao < 1 || opcao > 5);
       
       
        // OPCOES DO MENU       
        switch (opcao) {
           
            // MEDIA ARITMETICA SIMPLES
            case 1:
                for (int i = 0; i <= 4; i++) {
                    printf("Digite o %do numero: ", i+1);
                    scanf("%f", &x[i]);
                }
                resultado = (x[0] + x[1] + x[2] + x[3] + x[4]) / 5.0;
                printf("A media aritmetica simples desses numeros e %.2f", resultado);
                break;
               
               
            // MEDIA PONDERADA
            case 2:
                float pesos[5], numerador, denominador;
                numerador = 0;
                denominador = 0;
                for (int i = 0; i <= 4; i++) {
                    printf("Digite o %do numero: ", i+1);
                    scanf("%f", &x[i]);
                    printf("Digite o peso do %do numero: ", i+1);
                    scanf("%f", &pesos[i]);
                    numerador += pesos[i] * x[i];
                    denominador += pesos[i];
                }
                if (denominador != 0) {
                    resultado = numerador / denominador;
                    printf("A media aritmetica ponderada desses numeros e %.2f", resultado);
                }
                else {
                    printf("Nao e possivel efetuar o calculo (divisao por zero)");
                }
                break;
           
           
            // DESVIO PADRAO  
            case 3:
                for (int i = 0; i <= 4; i++) {
                    printf("Digite o %do numero: ", i+1);
                    scanf("%f", &x[i]);
                }
                float media = (x[0] + x[1] + x[2] + x[3] + x[4]) / 5.0;
                float somatorio = 0.0;
                for (int i = 0; i <= 4; i++) {
                    somatorio += pow((x[i] - media), 2.0);
                }
                resultado = sqrt(somatorio / 5.0);
                printf("O desvio padrao desses numeros e %.2f", resultado);
                break;
           
           
            // MAIOR VALOR  
            case 4:
                for (int i = 0; i <= 4; i++) {
                    printf("Digite o %do numero: ", i+1);
                    scanf("%f", &x[i]);
                }
                if ((x[0] >= x[1]) && (x[0] >= x[2]) && (x[0] >= x[3]) && (x[0] >= x[4])) {
                    printf("O maior valor desses numeros e %.2f", x[0]);
                }
                else if ((x[1] >= x[2]) && (x[1] >= x[3]) && (x[1] >= x[4])) {
                    printf("O maior valor desses numeros e %.2f", x[1]);
                }
                else if ((x[2] >= x[3]) && (x[2] >= x[4])) {
                    printf("O maior valor desses numeros e %.2f", x[2]);
                }
                else if (x[3] >= x[4]) {
                    printf("O maior valor desses numeros e %.2f", x[3]);
                }
                else {
                    printf("O maior valor desses numeros e %.2f", x[4]);
                }
                break;
           
           
            // MENOR VALOR  
            case 5:
                for (int i = 0; i <= 4; i++) {
                    printf("Digite o %do numero: ", i+1);
                    scanf("%f", &x[i]);
                }
                if ((x[0] <= x[1]) && (x[0] <= x[2]) && (x[0] <= x[3]) && (x[0] <= x[4])) {
                    printf("O menor valor desses numeros e %.2f", x[0]);
                }
                else if ((x[1] <= x[2]) && (x[1] <= x[3]) && (x[1] <= x[4])) {
                    printf("O menor valor desses numeros e %.2f", x[1]);
                }
                else if ((x[2] <= x[3]) && (x[2] <= x[4])) {
                    printf("O menor valor desses numeros e %.2f", x[2]);
                }
                else if (x[3] <= x[4]) {
                    printf("O menor valor desses numeros e %.2f", x[3]);
                }
                else {
                    printf("O menor valor desses numeros e %.2f", x[4]);
                }
                break;
        }
       
       
        //VERIFICAR SE O USUARIO DESEJA EXECUTAR NOVAMENTE O CODIGO
        printf("\n\n   Para finalizar o programa, digite 0.\n   Para executar novamente, digite um numero diferente de 0\n   ");
        scanf("%d", &final);
        printf("\n"); 
            
    } while (final != 0); //EXECUTA OU FINALIZA O CODIGO
}

