#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Primeiro, encontre o menor elemento do array, trocando esse elemento pelo elemento da primeira posição. A seguir, encontre o segundo menor elemento e troque-o com o elemento da segunda posição. Continue dessa forma até que todo o array esteja ordenado. Esse método é chamado de selection sort.
// O tempo de execução é sempre igual independente da disposição dos elementos no array (dependendo somente do seu tamanho).

extern void sort(Item *a, int lo, int hi){
    for (int i=lo; i<hi; i++){
        for (int j=i+1; j<hi; j++){
            compexch(key(a[i]), key(a[j]));
        }
    }
}
