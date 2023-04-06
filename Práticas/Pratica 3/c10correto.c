#include <stdlib.h>
#include <stdio.h>

int main(void)
{
        int *p;
        p = malloc(128); //alocando 128 bytes para o ponteiro p
        for(int i = 0; i < 32; i++) // 32 iterações é o limite, já que um int ocupa 4 bytes
        {
            p[i] = i;
            printf("%d\n", p[i]);
        }

        free(p);
}
