#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int *a = malloc(sizeof(int) * 10);
  if (!a) return -1; /*malloc failed*/
  for (i = 0; i < 10; i++){ // devemos por o limite da iteração de i até 10 devido a alocação de 40 bytes feita pelo malloc
    a[i] = i;
  }
  free(a);
  return 0;
}

