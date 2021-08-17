#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// O shaker sort também é chamado de bubble sort bidirecional, porque o array é percorrido nas duas direções a cada passada. Em alguns casos, o shaker sort é mais rápido que o bubble sort, em particular por fazer melhor uso da localidade de cache.

void shaker_sort(Item *a, int lo, int hi){
    int sobe=lo;
    int desce=hi-1;
    while(sobe<desce){ // SE O PONTEIRO QUE SOBE ULTRAPASSAR O QUE DESCE, O VETOR ESTÁ ORDENADO.
        for(int i=sobe; i<desce; i++){ //"ida" para a direita
            compexch(key(a[i]), key(a[i+1]));
        }
        desce--; //diminui pois o elemento com maior valor já está na extrema direita
        for(int i=desce; i>sobe; i--){ //"ida" para a esquerda
            compexchr(key(a[i]), key(a[i-1])); // "compexch reversed"
        }
        sobe++; //aumenta pois o elemento com menor valor já está na extrema esquerda
    }
}

void sort(Item *a, int lo, int hi){
    shaker_sort(a, lo, hi);
}