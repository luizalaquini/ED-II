#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

void printArray(int* array, int n){
    for(int i =0; i<n;i++)
        printf("%d ",array[i]);

    printf("\n");
}

int main (){
    int N; 

    //1. Receber como um parâmetro o número N de itens a serem ordenados.
    scanf("%d", &N);
    
    //2. Alocar dinamicamente um array para guardar os N itens na memória.
    Item *array = (Item*) malloc (N * sizeof (Item));

    //3. Ler os N itens (no caso aqui, inteiros) de stdin para o array
    for (int i=0; i<N; i++) 
        scanf("%d", &array[i]);

    //4. Executar um algoritmo de ordenação e medir o seu tempo, como já feito em laboratórios anteriores.
    clock_t start, stop;
    
    start = clock();
    sort(array, 0, N);
    stop = clock();

    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    //5. Exibir o array ordenado em stdout.
    printArray(array, N);
    printf("Elapsed time: %.3f\n", time_taken);

    //6. Liberar a memória do array.
    free(array);

    return 0;
}