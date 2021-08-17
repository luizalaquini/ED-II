// Versão 7: altere a Versão 6 para implementar o merge skip na versão bottom-up.

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "insert_sort.c"

#define CUTOFF 20

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

    if (!less(a[mid+1], a[mid])) return;
    
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