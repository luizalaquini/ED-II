#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Fique percorrendo o array, trocando os elementos adjacentes que estão fora de ordem, até que toda a sequência esteja ordenada.

void bubble_sort(Item *a, int lo, int hi){
    for (int i=hi-1; i>lo; i--){
        for (int j=lo; j<i; j++){
            compexch(key(a[j]), key(a[j+1]));
        }
    }
}

void sort(Item *a, int lo, int hi){
    bubble_sort(a, lo, hi);
}