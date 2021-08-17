#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Um método muito utilizado pelas pessoas para ordenar uma mão em um jogo de cartas é considerar uma carta de cada vez, inserindo-a no seu local correto, mantendo a ordenação das cartas que já foram analisadas. Em uma implementação no computador, é necessário criar um espaço para o elemento sendo inserido, movendo os elementos maiores uma posição para a direita. Esse tipo de método de ordenação é chamado de insertion sort.
// Tempo de execução depende da ordenação e do tamanho do array.

// Minha versão
/*void insert_sort(Item *a, int lo, int hi){
    int min;
    for (int i=lo; i<hi; i++){
        min = i;
        for (int j=i+1; j<hi; j++)
            if (less(key(a[j]),key(a[min]))) min=j;
        exch(key(a[i]),key(a[min]));
    }
}*/

// Versão do prof
void insert_sort(Item *a, int lo, int hi) {
    for (int i = hi; i > lo; i--)
        compexch(a[i-1], a[i]);
    for (int i = lo+2; i <= hi; i++) {
        int j = i;
        Item v = a[i];
        while (less(v, a[j-1])) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

void sort(Item *a, int lo, int hi){
    insert_sort(a, lo, hi);
}

