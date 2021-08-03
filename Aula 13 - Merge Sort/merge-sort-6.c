// Versão 6: altere a Versão 5 para implementar o que seria o “cut-off ” na versão bottom-up.

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define CUTOFF 20

void insert_sort(Item *a, int lo, int hi){
    int min;
    for (int i=lo; i<hi; i++){
        min = i;
        for (int j=i+1; j<hi; j++)
            if (less(key(a[j]),key(a[min]))) min=j;
        exch(key(a[i]),key(a[min]));
    }
}

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++)
    aux[k] = a[k]; // Copy array

    int i = lo, j = mid+1;

    for (int k = lo; k <= hi; k++) { // Merge
        if (i > mid) a[k] = aux[j++];   
        else if (j > hi) a[k] = aux[i++];
        else if (less(aux[j], aux[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }

    int mid = lo + (hi - lo) / 2;

    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))

void sort(Item *a, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = malloc(N * sizeof(Item));

    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    
    free(aux);
}