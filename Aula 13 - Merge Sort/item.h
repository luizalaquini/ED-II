#ifndef ITEM_H
#define ITEM_H

typedef int Item;
#define key(A)          (A)
#define less(A, B)      (key(A) < key(B)) //verifica se é menor
#define exch(A, B)      { Item t = A; A = B; B = t; } //faz a troca de posições
#define compexch(A, B)  if (less(B, A)) exch(A, B) //algoritmo = verifica + troca
#define compexchr(A, B) if (!less(B, A)) exch(A, B) //algoritmo inverso (reversed)

#endif /* ITEM_H */