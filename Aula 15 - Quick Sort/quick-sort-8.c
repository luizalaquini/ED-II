/*Versão 8: implemente o quick sort top-down com o particionamento 3-way de Dijkstra.*/

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo) return;

    Item v = a[lo];
    int lt = lo, gt = hi, i = lo;

    while (i <= gt) {
        if (a[i] < v) {
            exch(a[lt], a[i]);
            lt++; i++;
        } else if (a[i] > v) {
            exch(a[i], a[gt]);
            gt--;
        } else {
            i++;
        }
    }

    quick_sort(a, lo, lt-1);
    quick_sort(a, gt+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}