/* Versão 3: quick sort top-down recursivo com mediana de 3. Implemente essa versão 
a partir da Versão 1, isto  ́e, não use cut-off.  Assim, comparando separadamente as 
versões você pode determinar o ganho individual de cada otimização.*/

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];
    
    while(1) {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi) break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo) break;
        if (i >= j) break; // Check if pointers cross.
        exch(a[i], a[j]);
    }

    exch(a[lo], a[j]); // Swap with partitioning item.
    return j; // Return index of item known to be in place.
}

// Minha função median_of_3 
/*int median_of_3(Item *a, int lo, int hi){
    int mi = (hi + lo)/2;
    Item x = a[lo];
    Item y = a[mi];
    Item z = a[hi];

    if (less(x, y)){
        if (less(y, z)) return mi;
        else if (less(x, z)) return hi;
        else return lo;
    }
    else {
        if (less(z, y)) return mi;
        else if (less(z, x)) return hi;
        else return lo;
    }
}*/

// Função median_of_3 do prof (melhor)
int median_of_3(Item *a, int lo, int hi) {
    int mid = lo + (hi-lo)/2;
    compexch(a[lo], a[hi]);
    compexch(a[lo], a[mid]);
    compexch(a[mid], a[hi]);
    return mid;
}

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);

    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}